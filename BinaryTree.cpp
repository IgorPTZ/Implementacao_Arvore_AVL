#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	root = NULL;
}

bool BinaryTree::isEmpty(NodeTree * obj) {
	return obj == NULL;
}

void BinaryTree::clean(int opcao, NodeTree *&obj) {
	if (isEmpty(obj)) {
		cout << "A arvore ja esta vazia, nao e possivel esvazia-la novamente\n";
		return;
	}

	if (opcao == 1) {
		makeEmpty();
	}
	else {
		destroy(obj);
		cout << "A arvore foi esvaziada e a memoria desalocada\n";
	}
}

void BinaryTree::insert(int num) {
	NodeTree * node = new NodeTree;
	node->value = num;

	insertInOrder(node, root);
}

int BinaryTree::height(NodeTree * obj) {
	if (obj == NULL) {
		return -1;
	}

	int hLeft = height(obj->left);

	int hRight = height(obj->right);

	if (hLeft > hRight)
		return (hLeft + 1);
	else
		return(hRight + 1);
}

void BinaryTree::printInOrder(NodeTree * obj) {
	if (obj == NULL)
		return;

	printInOrder(obj->left);

	cout << obj->value << " ";

	printInOrder(obj->right);
}

bool BinaryTree::balanced(NodeTree * root1) {
	if (root1 == NULL) {
		return true;
	}
	else {
		if (root1->left == NULL && root1->right == NULL) {
			return true;
		}
		else {
			if (root1->left != NULL && root1->right != NULL) {
				return (balanced(root1->left) == true && balanced(root1->right) == true);
			}
			else {

				int hLeft = height(root1->left);

				int hRight = height(root1->right);

				if ((hLeft - hRight) >= -1 && (hLeft - hRight) <= 1)
					return true;
				else
					return false;

			} // fim if..else interno 2

		} // fim if.. else interno 1

	} // if if..else externo
}// fim metodo balanced

int BinaryTree::numberNodes(NodeTree * obj) {
	if (obj == NULL)
		return 0;

	int nLeft = numberNodes(obj->left);

	int nRight = numberNodes(obj->right);

	return(nLeft + nRight + 1);
}

bool BinaryTree::perfBalanced(NodeTree * root1) {
	if (root1 == NULL) {
		return true;
	}
	else {
		if (root1->left == NULL && root1->right == NULL) {
			return true;
		}
		else {
			if (root1->left != NULL && root1->right != NULL) {

				bool perfBal1 = (perfBalanced(root1->left) == true && perfBalanced(root1->right) == true);

				bool perfBal2 = (numberNodes(root1->left) - numberNodes(root1->right) >= -1 && numberNodes(root1->left) - numberNodes(root1->right) <= 1);

				if (perfBal1 == true && perfBal2 == true) {
					return true;
				}
				else if (perfBal1 == false && perfBal2 == false) {
					return false;
				}
				else {
					return false;
				}

			}
			else {

				int nLeft = numberNodes(root1->left);

				int nRight = numberNodes(root1->right);

				if ((nLeft - nRight) >= -1 && (nLeft - nRight) <= 1)
					return true;
				else
					return false;
			}
		} // if..else interno
	} // if..else externo
} // fim metodo perfBalanced

void BinaryTree::menu(void) {
	int sentinela = 0;
	int numero;
	int opcao;

	while (sentinela != 7) {

		system("cls");
		cout << "Opcoes:\n\n"
			"1-Inserir ordenadamente\n"
			"2-Verificar balanceamento normal\n"
			"3-Verificar balanceamento perfeito\n"
			"4-Exibir em ordem\n"
			"5-Calcular altura\n"
			"6-Esvaziar arvore\n"
			"7-Sair\n\n"
			"Opcao desejada: ";
		cin >> sentinela;

		if (sentinela == 1) {
			system("cls");
			cout << "Digite um numero: ";
			cin >> numero;
			insert(numero);
		}

		if (sentinela == 2) {
			system("cls");

			if (balanced(root)) {
				cout << "A arvore esta balanceada\n";
			}
			else {
				cout << "A arvore nao esta balanceada\n";
			}

			system("PAUSE");
		}

		if (sentinela == 3) {
			system("cls");

			if (perfBalanced(root)) {
				cout << "A arvore esta balanceada perfeitamente\n";
			}
			else {
				cout << "A arvore nao esta balanceada perfeitamente\n";
			}

			system("PAUSE");
		}

		if (sentinela == 4) {
			system("cls");
			cout << "Exibicao em ordem: ";
			printInOrder(root);
			system("PAUSE");
		}

		if (sentinela == 5) {
			system("cls");
			cout << "Altura:" << height(root) << endl;
			system("PAUSE");
		}

		if (sentinela == 6) {
			system("cls");
			cout << "Escolha a opcao: 1-Esvaziar / 2- Esvaziar e desalocar memoria: ";
			cin >> opcao;
			clean(opcao, root);
			system("PAUSE");
		}
	}
}

void BinaryTree::makeEmpty() {
	root = NULL;
	cout << "A arvore foi esvaziada\n";
	return;
}

void BinaryTree::destroy(NodeTree *&obj) {
	if (!isEmpty(obj)) {
		destroy(obj->left);

		destroy(obj->right);

		delete(obj);
	}
	obj = NULL;
}

void BinaryTree::insertInOrder(NodeTree * node1, NodeTree *&root1) {
	if (root1 == NULL) {
		node1->left = NULL;
		node1->right = NULL;
		root1 = node1;
	}
	else {
		if (node1->value > root1->value) {
			insertInOrder(node1, root1->right);
		}
		else if (node1->value < root1->value) {
			insertInOrder(node1, root1->left);
		}
		else {
			return;
		}
	}
} // fim metodo insertInOrder

