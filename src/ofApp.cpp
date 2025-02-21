#include "ofApp.h"

LinkedList::~LinkedList() {
    while (head != nullptr) {
        deleteHead();
    }
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void LinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;

    }
    current->next = newNode;
}
void LinkedList::deleteHead() {
    if(head==nullptr)return;
    Node*temp=head;
    head=head->next;
    delete temp;
}

void LinkedList::deleteTail() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}
void LinkedList::sort() {
    if (head == nullptr || head->next == nullptr)return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        
    } while (swapped);
}

void ofApp::setup() {
    oscillationAmplitude = 50;
    cameraX = 0;
    nodeSpacing = 100;
    ofSetCircleResolution(50);
}

void ofApp::update() {
    float x = 100 - cameraX;
    Node* current = list.head;
    while (current != nullptr) {
        current->x = x;
        current->baseY = ofGetHeight() / 2;
        current->phase += 0.02;
        current->y = current->baseY + sin(current->phase) * oscillationAmplitude;
        x += nodeSpacing;
        current = current->next;
    }
}

void ofApp::draw() {
    ofBackground(0);
    ofSetColor(255);

    Node* current = list.head;
    while (current != nullptr) {
        if (current->next != nullptr) {
            ofDrawLine(current->x, current->y,
                current->next->x, current->next->y);
        }
        float radius = current->data * 2 + 20;
        ofDrawCircle(current->x, current->y, radius);
        ofSetColor(0);
        string str = ofToString(current->data);
        ofDrawBitmapString(str, current->x - 10, current->y + 5);
        ofSetColor(255);
        current = current->next;
    }
}

void ofApp::keyPressed(int key) {
    switch (key) {
    case 'q':
        list.insertAtHead(ofRandom(1, 20));
        break;
    case 'w':
        list.insertAtTail(ofRandom(1, 20));
        break;
    case 'a':
        list.deleteHead();
        break;
    case 's':
        list.deleteTail();
        break;
    case 'e':
        list.sort();
        break;
    case 'z':
        oscillationAmplitude += 10;
        break;
    case 'x':
        oscillationAmplitude = max(0.0f, oscillationAmplitude - 10);
        break;
    case OF_KEY_LEFT:
        cameraX -= 50;
        break;
    case OF_KEY_RIGHT:
        cameraX += 50;
        break;
    }
}
