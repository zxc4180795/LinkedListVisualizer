#pragma once

#include "ofMain.h"

class Node {
	public:
		int data;
		Node* next;
		float x, y;
		float baseY;
		float phase;
		Node(int value) :data(value), next(nullptr), x(0), y(0), baseY(0), phase(0) {}
};

class LinkedList {
public:
	Node* head;
	LinkedList() :head(nullptr) {}
	~LinkedList();

	void insertAtHead(int value);
	void insertAtTail(int value);
	void deleteHead();
	void deleteTail();
	void sort();
};

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

private:
	LinkedList list;
	float oscillationAmplitude;
	float cameraX;
	float nodeSpacing;

};
