#include "Demo.h"

int main() {

	{
		Demo app;
		app.Init(750, 750, "Exedra");

		app.Run();
	}

	//std::cin.get();

	return 0;
}