//#include<iostream>
//#include<vector>
//
//class bullshit
//{
//public:
//	bullshit();
//	~bullshit();
//	void print();
//
//private:
//	struct node
//	{
//		node(/*int value*/);
//		//int value;
//		bool wall;
//		bool path;
//		node* up;
//		node* down;
//		node* left;
//		node* right;
//
//	};
//
//	std::vector<std::vector<node*>> Nodes;
//};
//
//bullshit::node::node(/*int value*/) {
//	//this->value = value;
//	this->wall = false;
//	this->path = false;
//	this->up = nullptr;
//	this->down = nullptr;
//	this->left = nullptr;
//	this->right = nullptr;
//}
//
//bullshit::bullshit()
//{
//	//int value = 0;
//	node* v2;
//	std::vector<node*> n;
//	for (int i = 0; i < 11; i++) {
//
//		for (int j = 0; j < 11; j++) {
//			n.push_back(v2);
//
//		}
//		delete v2;
//		Nodes.push_back(n);
//
//	}
//}
//
//bullshit::~bullshit()
//{
//	for (int i = 0; i < Nodes.size(); i++) {
//		for (int j = 0; j < Nodes.size(); j++) {
//			if (!Nodes.empty()) {
//
//				Nodes.pop_back();
//			}
//		}
//	}
//}
//
//
//void bullshit::print() {
//
//	for (int i = 0; i < Nodes.size(); i++) {
//		for (int j = 0; j < Nodes.size(); j++) {
//
//			std::cout << Nodes[i][j];
//		}
//		std::cout << std::endl;
//	}
//
//}
//
//
//int main() {
//
//	bullshit k;
//	k.print();
//
//	return 0;
//}