#pragma once
#include "NodeTree.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {

public:
	// Construtor
	BinaryTree();
	
	// Metodo para verificar se arvore esta vazia
	bool isEmpty(NodeTree *);

	// Metodo que garante acesso as opções de esvaziamento da arvore
	void clean(int, NodeTree *&);

	// Metodo que criar o nó
	void insert(int);


	// Metodo para calcular altura da arvore
	int height(NodeTree *);

	// Metodo para imprimir arvore no trajeto Em-ordem
	void printInOrder(NodeTree *);

    // Metodo para verificar se a arvore esta balanceada
	bool balanced(NodeTree *);

	// Metodo para contar a quantidade de nós da arvore
	int numberNodes(NodeTree *);

	// Metodo para verificar se arvore esta perfeitamente balanceada
	bool perfBalanced(NodeTree *);

	// Metodo de acesso aos recursos da classe 
	void menu();

private:
	NodeTree * root;

	// Metodo para esvaziar a arvore (Sem desalocação de memoria)
	void makeEmpty();

	// Metodo para esvaziar a arvore (Com desalocação de memoria)
	void destroy(NodeTree *&);

	// Metodo para inserir os dados em ordem, gerando uma arvore de busca,nao adiciona elementos repetidos.
	void insertInOrder(NodeTree *, NodeTree *&);

};

#endif