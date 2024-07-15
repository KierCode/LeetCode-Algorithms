#include<iostream>
#include<algorithm>
#include<vector>


static void printElement(const std::string& i_element);
static void forEachNewline();

//notes on for_each and its uses
	//an STL algorithm using a range of begining to ending point with 
	//a specific function applied to the range 



static void forEachNewline() {
	std::vector<std::string> strings{ "The", "best", "revenge" };

	std::for_each(strings.begin(), strings.end(), printElement);
}

static void printElement(const std::string& i_element) {
	std::cout << i_element << "\n";
}





struct User {
	std::string name;
	std::string username;
};


static void forEachName() {
	std::vector<User> users = {
		{"Karen", "karen8934"},
		{"Lisa", "lisa_frank"},
		{"Connor", "connor08"},
		{"Lisa", "lisa2021"},
		{"Lisa", "lili"}
	};

	std::for_each(users.begin(), users.end(), [](const User& user) {
		if (user.name == "Lisa") {
			std::cout << "Search Results for " << user.name << ": " << user.username << std::endl;
		}
		});
}




int main() {

	//example from https://www.sandordargo.com/blog/2019/04/03/stl-algorithm-tutorial-part-2-for_each
	std::cout << "        Newline with for_each\n";
	forEachNewline();
	
	//for_each to find a specific string
	std::cout << "\n\n    Search for name\n";
	forEachName();
	



	return 0;
}