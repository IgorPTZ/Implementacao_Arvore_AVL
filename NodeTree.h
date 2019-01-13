#pragma once
class NodeTree {
public:
	
	// Construtor
	NodeTree() {
		value = 0;
	}
	int value;
	NodeTree * left;
	NodeTree * right;
};