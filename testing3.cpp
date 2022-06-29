//#include<iostream>
//#include<vector>
//#include<stack>
//
//class maze
//{
//public:
//	maze();
//	~maze();
//	void print();
//	void DFS();
//	void solve();
//
//
//
//private:
//
//	struct node
//	{
//
//		node();
//		bool visited;
//		char v;
//		int y;
//		int x;
//
//	};
//	void Walls(const maze::node data, const maze::node data2);
//	std::vector<maze::node> directions(const node data);
//	std::vector<std::vector<node>> nodeVec;
//	friend std::ostream& operator<<(std::ostream& cout, const maze::node& data);
//
//};
//
//maze::node::node() {
//	v = '#';
//	visited = false;
//	x = 0;
//	y = 0;
//}
//
//maze::maze()
//{
//	std::vector<node> n2;
//	node v2;
//	for (int i = 0; i < 23; i++) {
//
//		for (int j = 0; j < 23; j++) {
//
//			n2.push_back(v2);
//		}
//		nodeVec.push_back(n2);
//	}
//}
//
//std::ostream& operator<<(std::ostream& cout, const maze::node& data) {
//	cout << data.v;
//	return cout;
//}
//
//void maze::print() {
//
//	for (int i = 0; i < 23; i++) {
//
//		for (int j = 0; j < 23; j++) {
//
//			std::cout << nodeVec[i][j];
//		}
//		std::cout << std::endl;
//	}
//
//}
//
//void maze::DFS() {
//	std::stack<node> stack;
//	node current;
//	node start;
//	node end;
//	end.v = 'E';
//	nodeVec[10][7] = end;
//	end.visited = true;
//	start.visited = true;
//	start.v = 'S';
//
//	//nodeVec[x][y]
//	nodeVec[start.x = 1][start.y = 1] = start;
//	nodeVec[end.x = 22][end.y = 7].v = 'E';
//	stack.push(start);
//
//	std::vector<node> direction;
//
//	while (!stack.empty()) {
//		direction = directions(stack.top());
//		current = stack.top();
//
//
//		if (!direction.empty()) {
//			stack.pop();
//			stack.push(current);
//
//			node temp = direction[rand() % direction.size()];
//			nodeVec[temp.x][temp.y].visited = true;
//
//			Walls(temp, current);
//
//			stack.push(temp); // vi sen sätter den som vi slumpmässigt valde ut längst upp på stacken att sen ta bort den
//
//
//		}
//		else {
//
//
//			stack.pop();
//		}
//	}
//
//
//}
//
//std::vector<maze::node> maze::directions(const node data) {
//
//	std::vector<node> hold;
//	node temp;
//
//	if (data.x + 2 < 22 && nodeVec[data.x + 2][data.y].visited == false) {
//
//		if (nodeVec[data.x + 2][data.y].v == 'E') {
//			exit(1);
//		}
//		else {
//			temp.x = data.x + 2;
//			temp.y = data.y;
//			hold.push_back(temp);
//		}
//
//	}
//	if (data.x - 2 > 0 && nodeVec[data.x - 2][data.y].visited == false) {
//		if (nodeVec[data.x - 2][data.y].v == 'E') {
//			exit(1);
//		}
//		else
//		{
//			temp.x = data.x - 2;
//			temp.y = data.y;
//			hold.push_back(temp);
//		}
//
//	}
//
//	if (data.y + 2 < 22 && nodeVec[data.x][data.y + 2].visited == false) {
//		if (nodeVec[data.x][data.y + 2].v == 'E') {
//			exit(1);
//
//		}
//		else {
//			temp.x = data.x;
//			temp.y = data.y + 2;
//			hold.push_back(temp);
//		}
//
//	}
//
//	if (data.y - 2 > 0 && nodeVec[data.x][data.y - 2].visited == false) {
//		if (nodeVec[data.x][data.y - 2].v == 'E') {
//			exit(1);
//		}
//		else {
//			temp.x = data.x;
//			temp.y = data.y - 2;
//			hold.push_back(temp);
//
//		}
//
//	}
//
//
//
//	return hold;
//}
//
//
//void maze::Walls(const maze::node data, const maze::node data2) {
//
//
//
//	if (data.x > data2.x && data.y == data2.y) {
//		nodeVec[data.x - 1][data.y].v = ' ';
//		nodeVec[data.x][data.y].v = ' ';
//
//
//	}
//	else if (data.x < data2.x && data.y == data2.y) {
//		nodeVec[data.x + 1][data.y].v = ' ';
//		nodeVec[data.x][data.y].v = ' ';
//
//
//	}
//	else if (data.y > data2.y && data.x == data2.x) {
//		nodeVec[data.x][data.y - 1].v = ' ';
//		nodeVec[data.x][data.y].v = ' ';
//
//
//	}
//
//	else
//	{
//		nodeVec[data.x][data.y + 1].v = ' ';
//		nodeVec[data.x][data.y].v = ' ';
//
//	}
//
//}
//
//void maze::solve() {
//	std::stack<node> holding;
//	std::vector<node> path;
//	node start;
//	for (int i = 0; i < 23; i++) {
//		for (int j = 0; j < 23; j++) {
//			if (nodeVec[i][j].v == 'S') {
//				start = nodeVec[start.x = i][start.y = j];
//				nodeVec[start.x = i][start.y = j].visited = false;
//				holding.push(start);
//			}
//		}
//	}
//
//	while (!holding.empty()) {
//
//		if (start.x + 1 < 22 && nodeVec[start.x + 1][start.y].v == ' ') {
//			nodeVec[start.x + 1][start.y].v = '0';
//			start.x = start.x + 1;
//			holding.push(start);
//			if (nodeVec[start.x + 1][start.y].v == 'E') { break; }
//
//		}
//		else if (start.x - 1 > 0 && nodeVec[start.x - 1][start.y].v == ' ') {
//			nodeVec[start.x - 1][start.y].v = '0';
//			start.x = start.x - 1;
//			holding.push(start);
//			if (nodeVec[start.x - 1][start.y].v == 'E') { break; }
//
//		}
//		else if (start.y + 1 < 22 && nodeVec[start.x][start.y + 1].v == ' ') {
//			nodeVec[start.x][start.y + 1].v = '0';
//			start.y = start.y + 1;
//			holding.push(start);
//			if (nodeVec[start.x][start.y + 1].v == 'E') { break; }
//
//		}
//		else if (start.y - 1 > 0 && nodeVec[start.x][start.y - 1].v == ' ') {
//			nodeVec[start.x][start.y - 1].v = '0';
//			start.y = start.y - 1;
//			holding.push(start);
//			if (nodeVec[start.x][start.y - 1].v == 'E') { break; }
//
//		}
//		else
//		{
//
//			std::cout << holding.top().x << " " << holding.top().y << std::endl;
//			holding.pop();
//			nodeVec[start.x][start.y].v = '*';
//			print();
//			system("cls");
//
//
//
//			start = holding.top();
//		}
//	}
//
//
//}
//
//
//
//
//
//
//maze::~maze()
//{
//}
//
//int main() {
//	srand((unsigned)time(0));
//	maze j;
//
//	j.DFS();
//	//j.print();
//	j.solve();
//	j.print();
//
//	return 0;
//
//}