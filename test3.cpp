#include<iostream>
#include<vector>
#include<stack>

class maze
{
public:
	//deklarationen av publika funktioner
	maze();
	void print();
	void DFS();
	void solve();



private:

	struct node
	{

		node();
		bool visited;
		char v;
		int y;
		int x;

	};

	//deklarationen av privata som har n�got med noden att g�ra funktioner
	bool check_4_end(node data);
	void Walls(const maze::node data, const maze::node data2);
	std::vector<maze::node> directions(const node data);
	std::vector<std::vector<node>> nodeVec;
	friend std::ostream& operator<<(std::ostream& cout, const maze::node& data);

};

// initoalisering av v�r medl�mmar
maze::node::node() {
	v = '#';
	visited = false;
	x = 0;
	y = 0;
}

// defualt konstruktorn som fyler vektorn med nodar
maze::maze()
{
	std::vector<node> n2;
	node v2;
	for (int i = 0; i < 33; i++) {

		for (int j = 0; j < 33; j++) {

			n2.push_back(v2);
		}
		nodeVec.push_back(n2);
	}
}

// �verlagring av utstr�m oparatorn f�r att kunna skriva ut mazen.
std::ostream& operator<<(std::ostream& cout, const maze::node& data) {
	cout << data.v;
	return cout;
}

// funktionen att skriva ut mazen
void maze::print() {

	for (int i = 0; i < 33; i++) {

		for (int j = 0; j < 33; j++) {

			std::cout << nodeVec[i][j];
		}
		std::cout << std::endl;
	}

}

// funktionen att generera mazen 
void maze::DFS() {

	std::stack<node> stack; // stacken h�ller de st�llen som vi har varit p� s� att vi inte g� till samma st�lle f�r andra g�ngen och f�r att sendan hj�lpa oss baktraka n�r det inte finns n�nstance att g�.
	node current;          // en cuurent node som representerar vilken node vi liger p� i l�gget
	node start;
	node end;
	end.v = 'E';
	nodeVec[10][7] = end;  // positionen av v�r slut punkten
	start.visited = true;  // H�r s�tter vi visitted till start noden till true s� att vi ska inte g� tillbaka till den noden f�r att vi har redan varit d�r.
	start.v = 'S';

	//nodeVec[x][y]
	nodeVec[start.x = 1][start.y = 1] = start;  // positionera var v�r start node ska vara
	nodeVec[end.x = 32][end.y = 7].v = 'E';		// positionera var v�r end node ska vara	
	stack.push(start);							//s�tter start noden i stacken eftersom det �r d�r vi bes�ker f�rst

	std::vector<node> direction;               // en vektor som h�ller alla riktningar som vi kan g� 

	while (!stack.empty()) {                    // kolla om stacken �r tom 
		direction = directions(stack.top()); // anroppar directions funktion p� noden som ligger p� topen av stacken som h�mtar alla riktningar vi kan g� till s� l�nge de �r obes�kt och spara de i dirction vektorn
		current = stack.top();				  // sedan spara vi v�r node i current att sen kunna anv�nda det f�r att j�mf�ra p� vilken position vi ska g� till i vektorn


		if (!direction.empty()) {           // h�r kollar vi om direction vektor �r inte tom d� vet vi att det finns en riktning vi kan tar oss till 
			/*stack.pop();
			stack.push(current);*/

			node temp = direction[rand() % direction.size()];	// 	v�ljer en slumpm�sigt riktning fr�n vektorn och markerar den positionen som bes�kt
			nodeVec[temp.x][temp.y].visited = true;

			Walls(temp, current);       // anroppar funktionen walls som tar bort v�ggarnar och g�r det till en v�g

			stack.push(temp); // vi sen s�tter den som vi slumpm�ssigt valde ut l�ngst upp p� stacken


		}
		else {

			// om direction vektorn �r tom betyder det att det finns ingenstance att g� s� popar vi den positionen fr�n stacken s� att vi kan hamna p� positionen vi var p� innan det.
			stack.pop();
		}
	}


}


//hella den h�r funktionen �r f�r att kolla om det m�jlight att g� i en viss riktning om det �r m�jlight d� stoppar vi den riktingen i vektorn hold och retetunera hella vektorn hold

std::vector<maze::node> maze::directions(const node data) {

	std::vector<node> hold;
	node temp;

	if (data.x + 2 < 32 && nodeVec[data.x + 2][data.y].visited == false) {  // kolla om vi kan g� h�ger och inte hamnar utanf�r vektorn

		if (nodeVec[data.x + 2][data.y].v == 'E') {
			exit(1);
		}
		else {
			temp.x = data.x + 2;
			temp.y = data.y;
			hold.push_back(temp);
		}

	}
	if (data.x - 2 > 0 && nodeVec[data.x - 2][data.y].visited == false) { // kolla om vi kan g� v�nster och inte hamnar utanf�r vektorn

		if (nodeVec[data.x - 2][data.y].v == 'E') {
			exit(1);
		}
		else
		{
			temp.x = data.x - 2;
			temp.y = data.y;
			hold.push_back(temp);
		}

	}

	if (data.y + 2 < 32 && nodeVec[data.x][data.y + 2].visited == false) { // kolla om vi kan g� ner �t och inte hamnar utanf�r vektorn

		if (nodeVec[data.x][data.y + 2].v == 'E') {
			exit(1);

		}
		else {
			temp.x = data.x;
			temp.y = data.y + 2;
			hold.push_back(temp);
		}

	}

	if (data.y - 2 > 0 && nodeVec[data.x][data.y - 2].visited == false) { // kolla om vi kan g� upp �t och inte hamnar utanf�r vektorn

		if (nodeVec[data.x][data.y - 2].v == 'E') {
			exit(1);
		}
		else {
			temp.x = data.x;
			temp.y = data.y - 2;
			hold.push_back(temp);

		}

	}



	return hold;
}


void maze::Walls(const maze::node data, const maze::node data2) {

	//efter att vi har valt ut i vilken riktning vi ska g� g�r vi en v�g.

	if (data.x > data2.x && data.y == data2.y) {
		nodeVec[data.x - 1][data.y].v = ' ';
		nodeVec[data.x][data.y].v = ' ';


	}
	else if (data.x < data2.x && data.y == data2.y) {
		nodeVec[data.x + 1][data.y].v = ' ';
		nodeVec[data.x][data.y].v = ' ';


	}
	else if (data.y > data2.y && data.x == data2.x) {
		nodeVec[data.x][data.y - 1].v = ' ';
		nodeVec[data.x][data.y].v = ' ';


	}

	else
	{
		nodeVec[data.x][data.y + 1].v = ' ';
		nodeVec[data.x][data.y].v = ' ';

	}

}

void maze::solve() {
	std::stack<node> holding;
	std::vector<node> path;
	node start;
	for (int i = 0; i < 33; i++) {
		for (int j = 0; j < 33; j++) {
			if (nodeVec[i][j].v == 'S') {
				start = nodeVec[start.x = i][start.y = j];
				nodeVec[start.x = i][start.y = j].visited = false;
				holding.push(start);
			}
		}
	}

	while (!holding.empty()) {

		if (check_4_end(start)) {

			for (int i = 0; i < 33; i++) {
				for (int j = 0; j < 33; j++) {

					if (nodeVec[i][j].v == '*') {
						nodeVec[i][j].v = ' ';
					}

				}
			}
			std::cout << " MAZE SOLVED" << std::endl;
			break;

		}
		else
		{
			if (start.x + 1 < 32 && nodeVec[start.x + 1][start.y].v == ' ') {
				nodeVec[start.x + 1][start.y].v = '.';
				start.x = start.x + 1;
				holding.push(start);
				if (nodeVec[start.x + 1][start.y].v == 'E') { break; }

			}
			else if (start.x - 1 > 0 && nodeVec[start.x - 1][start.y].v == ' ') {
				nodeVec[start.x - 1][start.y].v = '.';
				start.x = start.x - 1;
				holding.push(start);
				if (nodeVec[start.x - 1][start.y].v == 'E') { break; }

			}
			else if (start.y + 1 < 32 && nodeVec[start.x][start.y + 1].v == ' ') {
				nodeVec[start.x][start.y + 1].v = '.';
				start.y = start.y + 1;
				holding.push(start);
				if (nodeVec[start.x][start.y + 1].v == 'E') { break; }

			}
			else if (start.y - 1 > 0 && nodeVec[start.x][start.y - 1].v == ' ') {
				nodeVec[start.x][start.y - 1].v = '.';
				start.y = start.y - 1;
				holding.push(start);
				if (nodeVec[start.x][start.y - 1].v == 'E') { break; }

			}
			else
			{
				holding.pop();
				nodeVec[start.x][start.y].v = '*';
				start = holding.top();
			}

		}


	}


}

bool maze::check_4_end(node data) {

	if (nodeVec[data.x][data.y - 1].v == 'E' || nodeVec[data.x][data.y + 1].v == 'E' || nodeVec[data.x + 1][data.y].v == 'E' || nodeVec[data.x - 1][data.y].v == 'E') { return true; }
	else
	{
		return false;
	}

}


int main() {

	srand((unsigned)time(0));
	std::cout << " WELCOME TO MY PROGRAME, HOPE YOU LOVE IT" << std::endl;


	std::cout << " PRESS 1: TO GENERATE MAZE" << std::endl;
	std::cout << " PRESS 2: TO EXIT" << std::endl;

	std::string input;
	std::cin >> input;

	while (input != "2") {

		while (input == "1" || input == "2") {

			if (input == "2") { break; }
			else
			{
				maze j;

				j.DFS();
				j.print();
				std::cout << "   " << std::endl;
				j.solve();
				j.print();
				std::cout << " PRESS 1: TO GENERATE MAZE" << std::endl;
				std::cout << " PRESS 2: TO EXIT" << std::endl;
				std::cin >> input;

				system("cls");
			}



		}

		if (input == "2") { std::cout << " THANK YOU FOR BEING WITH US YOU ARE ALWAYS WELCOME BACK  " << std::endl; break; }

		system("cls");
		std::cout << " WRONG INPUT! PLEASE TRY AGAIN" << std::endl;
		std::cout << "   " << std::endl;

		std::cout << " PRESS 1: TO GENERATE MAZE" << std::endl;
		std::cout << " PRESS 2: TO EXIT" << std::endl;
		std::cin >> input;
	}


	return 0;

}