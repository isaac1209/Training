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

	//deklarationen av privata som har något med noden att göra funktioner
	bool check_4_end(node data);
	void Walls(const maze::node data, const maze::node data2);
	std::vector<maze::node> directions(const node data);
	std::vector<std::vector<node>> nodeVec;
	friend std::ostream& operator<<(std::ostream& cout, const maze::node& data);

};

// initoalisering av vår medlämmar
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

// överlagring av utström oparatorn för att kunna skriva ut mazen.
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

	std::stack<node> stack; // stacken håller de ställen som vi har varit på så att vi inte gå till samma ställe för andra gången och för att sendan hjälpa oss baktraka när det inte finns nånstance att gå.
	node current;          // en cuurent node som representerar vilken node vi liger på i lägget
	node start;
	node end;
	end.v = 'E';
	nodeVec[10][7] = end;  // positionen av vår slut punkten
	start.visited = true;  // Här sätter vi visitted till start noden till true så att vi ska inte gå tillbaka till den noden för att vi har redan varit där.
	start.v = 'S';

	//nodeVec[x][y]
	nodeVec[start.x = 1][start.y = 1] = start;  // positionera var vår start node ska vara
	nodeVec[end.x = 32][end.y = 7].v = 'E';		// positionera var vår end node ska vara	
	stack.push(start);							//sätter start noden i stacken eftersom det är där vi besöker först

	std::vector<node> direction;               // en vektor som håller alla riktningar som vi kan gå 

	while (!stack.empty()) {                    // kolla om stacken är tom 
		direction = directions(stack.top()); // anroppar directions funktion på noden som ligger på topen av stacken som hämtar alla riktningar vi kan gå till så länge de är obesökt och spara de i dirction vektorn
		current = stack.top();				  // sedan spara vi vår node i current att sen kunna använda det för att jämföra på vilken position vi ska gå till i vektorn


		if (!direction.empty()) {           // här kollar vi om direction vektor är inte tom då vet vi att det finns en riktning vi kan tar oss till 
			/*stack.pop();
			stack.push(current);*/

			node temp = direction[rand() % direction.size()];	// 	väljer en slumpmäsigt riktning från vektorn och markerar den positionen som besökt
			nodeVec[temp.x][temp.y].visited = true;

			Walls(temp, current);       // anroppar funktionen walls som tar bort väggarnar och gör det till en väg

			stack.push(temp); // vi sen sätter den som vi slumpmässigt valde ut längst upp på stacken


		}
		else {

			// om direction vektorn är tom betyder det att det finns ingenstance att gå så popar vi den positionen från stacken så att vi kan hamna på positionen vi var på innan det.
			stack.pop();
		}
	}


}


//hella den här funktionen är för att kolla om det möjlight att gå i en viss riktning om det är möjlight då stoppar vi den riktingen i vektorn hold och retetunera hella vektorn hold

std::vector<maze::node> maze::directions(const node data) {

	std::vector<node> hold;
	node temp;

	if (data.x + 2 < 32 && nodeVec[data.x + 2][data.y].visited == false) {  // kolla om vi kan gå höger och inte hamnar utanför vektorn

		if (nodeVec[data.x + 2][data.y].v == 'E') {
			exit(1);
		}
		else {
			temp.x = data.x + 2;
			temp.y = data.y;
			hold.push_back(temp);
		}

	}
	if (data.x - 2 > 0 && nodeVec[data.x - 2][data.y].visited == false) { // kolla om vi kan gå vänster och inte hamnar utanför vektorn

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

	if (data.y + 2 < 32 && nodeVec[data.x][data.y + 2].visited == false) { // kolla om vi kan gå ner åt och inte hamnar utanför vektorn

		if (nodeVec[data.x][data.y + 2].v == 'E') {
			exit(1);

		}
		else {
			temp.x = data.x;
			temp.y = data.y + 2;
			hold.push_back(temp);
		}

	}

	if (data.y - 2 > 0 && nodeVec[data.x][data.y - 2].visited == false) { // kolla om vi kan gå upp åt och inte hamnar utanför vektorn

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

	//efter att vi har valt ut i vilken riktning vi ska gå gör vi en väg.

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