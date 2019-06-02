#include "Login.h"
#define LENGTH 10

using namespace std;

Login::Login()
{
	Login *l;
	SDL_StartTextInput();
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Game", 100, 100, 400, 400, SDL_WINDOW_SHOWN);
		if (window)
		{
			cout << "Window created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 10, 10, 100, 255);
			cout << "Renderer created!" << endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	name = "";
	Password = "";
	Choice = TextureManager::loadText("BREAKOUT", renderer, 60);
	SDL_QueryTexture(Choice, NULL, NULL, &texW, &texH);
	Button = TextureManager::loadTex("pirmas.bmp", renderer);
	tologin = TextureManager::loadText("LOGIN", renderer, 40);
	toregister = TextureManager::loadText("REGISTER", renderer, 40);
	SDL_QueryTexture(tologin, NULL, NULL, &texW1, &texH1);
	SDL_QueryTexture(toregister, NULL, NULL, &texW2, &texH2);
	username = TextureManager::loadText("Username: ", renderer, 40);
	password = TextureManager::loadText("Password: ", renderer, 40);
	SDL_QueryTexture(username, NULL, NULL, &texW3, &texH3);
	SDL_QueryTexture(password, NULL, NULL, &texW4, &texH4);
	goBack = TextureManager::loadText("GO BACK", renderer, 30);
	SDL_QueryTexture(goBack, NULL, NULL, &tW5, &tH5);
	BestPlayers = TextureManager::loadText("Best players", renderer, 30);
	SDL_QueryTexture(BestPlayers, NULL, NULL, &tW6, &tH6);
}

Login::~Login()
{
	SDL_DestroyTexture(textureName1);
	SDL_DestroyTexture(textureName2);
	SDL_DestroyTexture(textureName3);
	SDL_DestroyTexture(Choice);
	SDL_DestroyTexture(Button);
	SDL_DestroyTexture(tologin);
	SDL_DestroyTexture(toregister);
	SDL_DestroyTexture(username);
	SDL_DestroyTexture(password);
	SDL_DestroyTexture(goBack);
	SDL_DestroyTexture(BestPlayers);
	SDL_FreeSurface(surfaceName1);
	SDL_FreeSurface(surfaceName2);
	SDL_FreeSurface(surfaceName3);
	SDL_StopTextInput();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Login::ReadFromFile()
{
	ifstream myFile("Username.bin", ios::in | ios::binary);
	char str[LENGTH];
	if (myFile) 
	{
		while (myFile.read(str, LENGTH))
		{
			Names.push_back(str);
		}
		myFile.close();
	}

	ifstream file("Password.bin", ios::in | ios::binary);
	char str1[LENGTH];
	if (file) 
	{
		while (file.read(str1, LENGTH))
		{
			Passwords.push_back(str1);
		}
		file.close();
	}
	ifstream File("Points.bin", ios::in | ios::binary);
	char str2[LENGTH];
	if (File)
	{
		while (File.read(str1, LENGTH))
		{
			Points.push_back(str2);
		}
		File.close();
	}
	sort(Points.begin(), Points.end());
}

void Login::SaveToFile()
{
	ofstream myFile;
	myFile.open("Username.bin", ios::out | ios::binary | ios::app);
	if (myFile.is_open())
	{
		const char *name1 = new char[LENGTH];
		name1 = name.c_str();
		myFile.write(name1, LENGTH);
		cout << "Irasomas vardas: " << name1 << endl;

		myFile.close();
	}
	ofstream file;
	file.open("Password.bin", ios::out | ios::binary | ios::app);
	if (file.is_open())
	{
		const char * password1 = new char[LENGTH];
		password1 = Password.c_str();
		file.write(password1, LENGTH);
		cout << "Irasomas password: " << password1 << endl;
		file.close();
	}
}

void Login::EnterUsername()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
		{
			system("cls");
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (i == 1 && name[0] != NULL)
				{
					name = name.substr(0, name.length() - 1);
					SDL_RenderClear(renderer);
				}
				else if (i == 2 && Password[0] != NULL)
				{
					Password = Password.substr(0, Password.length() - 1);
					SDL_RenderClear(renderer);
				}
			}
			else if (event.type == SDL_TEXTINPUT)
			{
				if (i == 1 && name.length() <= LENGTH)
				{
					cout << "----" << name << endl;
					name += event.text.text;
					cout << "----" << name << endl;
				}
				if (i == 2 && Password.length() <= LENGTH)
				{
					cout << "----" << Password << endl;
					Password += event.text.text;
					cout << "----" << Password << endl;
				}
			}
		}
	}
	if (i == 1)
	{
		const char * name1 = name.c_str();
		surfaceName1 = TTF_RenderText_Solid(font, name1, color);
		textureName1 = SDL_CreateTextureFromSurface(renderer, surfaceName1);
		SDL_QueryTexture(textureName1, NULL, NULL, &W, &H);
		SDL_Rect destrect1 = { 20, 80, W, H };
		SDL_RenderCopy(renderer, textureName1, NULL, &destrect1);
	}
	if (i == 2)
	{ 
		const char * password1 = Password.c_str();
		surfaceName2 = TTF_RenderText_Solid(font, password1, color);
		textureName2 = SDL_CreateTextureFromSurface(renderer, surfaceName2);
		SDL_QueryTexture(textureName2, NULL, NULL, &W2, &H2);
		SDL_Rect destrect2 = { 20, 180, W2, H2 };
		SDL_RenderCopy(renderer, textureName2, NULL, &destrect2);
	}
}

void Login::login()
{
	ReadFromFile();
	int length = Passwords.size();
	/*bool operator=(const Login &l)
	{
		return (name == l.name);
	}*/
	for (int i = 0; i < length; i++)
	{
		if ((Names[i] == (name)) && (Passwords[i] == Password))
		{
			cout << "Login successful" << endl;
			isRunning = false;
		}
		cout << Names[i] << endl;
		cout << Passwords[i] << endl;
	}
	if (isRunning == true)
	{
		cout << "Username or password is incorrect" << endl;
		name = "";
		Password = "";
	}
}

void Login::Register()
{
	ReadFromFile();
	int length = Names.size();
	cout << length << endl;
	for (int i = 0; compare(i, length); i++)
	{
		if (Names[i] == name)
		{
			cout << "This name already exists" << endl;
			name = "";
			Password = "";
		}
		else m++;
	}
	if (m == length)
	{
		Names.push_back(name);
		Passwords.push_back(Password);
		cout << "Registration succsessful" << endl;
		SaveToFile();
		name = "";
		Password = "";
		cout << "Now you can login" << endl;
	}
}

void Login::render()
{
	SDL_RenderClear(renderer);
	if (n == 0)
	{
		SDL_Rect destChoice = { 30, 15, texW, texH };
		SDL_Rect destl = { 135, 112, texW1, texH1 };
		SDL_Rect destr = { 100, 202, texW2, texH2 };
		SDL_Rect destB = { 120, 305, tW6, tH6 };
		SDL_RenderCopy(renderer, Choice, NULL, &destChoice);
		SDL_RenderCopy(renderer, Button, NULL, &destL);
		SDL_RenderCopy(renderer, Button, NULL, &destR);
		SDL_RenderCopy(renderer, Button, NULL, &destBest);
		SDL_RenderCopy(renderer, tologin, NULL, &destl);
		SDL_RenderCopy(renderer, toregister, NULL, &destr);
		SDL_RenderCopy(renderer, BestPlayers, NULL, &destB);
	}
	if (n == 1)
	{
		SDL_Rect destu = { 15, 30, texW3, texH3 };
		SDL_Rect destp = { 15, 130, texW4, texH4 };
		SDL_Rect destGO = { 20, 240, texW1, texH1 };
		SDL_Rect destBACK = { 248, 245, tW5, tH5 };
		SDL_RenderCopy(renderer, username, NULL, &destu);
		SDL_RenderCopy(renderer, password, NULL, &destp);
		SDL_RenderCopy(renderer, Button, NULL, &destU);
		SDL_RenderCopy(renderer, Button, NULL, &destP);
		SDL_RenderCopy(renderer, Button, NULL, &destgo);
		SDL_RenderCopy(renderer, Button, NULL, &destback);
		SDL_RenderCopy(renderer, tologin, NULL, &destGO);
		SDL_RenderCopy(renderer, goBack, NULL, &destBACK);
		
		if (i == 1)
		{
			EnterUsername();
		}
		SDL_Rect destrect1 = { 20, 80, W, H };
		SDL_RenderCopy(renderer, textureName1, NULL, &destrect1);
		if (i == 2)
		{
			EnterUsername();
		}
		SDL_Rect destrect2 = { 20, 180, W2, H2 };
		SDL_RenderCopy(renderer, textureName2, NULL, &destrect2);
	}
	if (n == 2)
	{
		SDL_Rect destu = { 15, 30, texW3, texH3 };
		SDL_Rect destp = { 15, 130, texW4, texH4 };
		SDL_Rect destGO = { 20, 240, texW1, texH1 };
		SDL_Rect destBACK = { 248, 245, tW5, tH5 };
		SDL_RenderCopy(renderer, username, NULL, &destu);
		SDL_RenderCopy(renderer, password, NULL, &destp);
		SDL_RenderCopy(renderer, Button, NULL, &destU);
		SDL_RenderCopy(renderer, Button, NULL, &destP);
		SDL_RenderCopy(renderer, Button, NULL, &destgo);
		SDL_RenderCopy(renderer, Button, NULL, &destback);
		SDL_RenderCopy(renderer, toregister, NULL, &destGO);
		SDL_RenderCopy(renderer, goBack, NULL, &destBACK);
		
		if (i == 1)
		{
			EnterUsername();
			
		}
		SDL_Rect destrect1 = { 20, 80, W, H };
		SDL_RenderCopy(renderer, textureName1, NULL, &destrect1);
		if (i == 2)
		{
			EnterUsername();	
		}
		SDL_Rect destrect2 = { 20, 180, W2, H2 };
		SDL_RenderCopy(renderer, textureName2, NULL, &destrect2);
	}
	if (n == 3)
	{
		ReadFromFile();
		SDL_Rect destBACK = { 248, 245, tW5, tH5 };
		SDL_RenderCopy(renderer, Button, NULL, &destback);
		SDL_RenderCopy(renderer, goBack, NULL, &destBACK);
		int length = Names.size();
		/*for (N= Names.begin(), y =10; N < Names.end(); N++, y+=30)
		{
			const char * name1 = (*N).c_str();
			surfaceName1 = TTF_RenderText_Solid(font, name1, color);
			textureName1 = SDL_CreateTextureFromSurface(renderer, surfaceName1);
			SDL_QueryTexture(textureName1, NULL, NULL, &W, &H);
			SDL_Rect destrect1 = { 5, y, W, H };
			SDL_RenderCopy(renderer, textureName1, NULL, &destrect1);
		}*/
		for (int i =0, y = 10; i < length; i++, y += 30)
		{
			const char * name1 = Names[i].c_str();
			surfaceName1 = TTF_RenderText_Solid(font, name1, color);
			textureName1 = SDL_CreateTextureFromSurface(renderer, surfaceName1);
			SDL_QueryTexture(textureName1, NULL, NULL, &W, &H);
			SDL_Rect destrect1 = { 5, y, W, H };
			SDL_RenderCopy(renderer, textureName1, NULL, &destrect1);
		}

		int l = Points.size();
		for (int i = 0; i < l; i++)
		{
			const char* p = Points[i].c_str();
			surfaceName3 = TTF_RenderText_Solid(font, p, color);
			textureName3 = SDL_CreateTextureFromSurface(renderer, surfaceName3);
			SDL_QueryTexture(textureName3, NULL, NULL, &W3, &H3);
			SDL_Rect destrect3 = { 100, y, W3, H3 };
			SDL_RenderCopy(renderer, textureName3, NULL, &destrect3);
		}
	}
	SDL_RenderPresent(renderer);
}

void Login::update()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			isRunning = false;
		}
	case SDL_MOUSEBUTTONDOWN:
		if (n == 0)
		{
			if (event.motion.x >= x && event.motion.x <= w+x && event.motion.y >= y & event.motion.y <= y+h)
			{
				cout << "LOGIN!" << endl;
				n = 1;
			}
			else if (event.motion.x >= x && event.motion.x <= w+x && event.motion.y >= y+x & event.motion.y <= y+h+x)
			{
				cout << "REGISTER!" << endl;
				n = 2;
			}
			if (event.motion.x >= x && event.motion.x <= w + x && event.motion.y >= 2 * y + x & event.motion.y <= 2 * y + h + x)
			{
				cout << "Best Players" << endl;
				n = 3;
			}
		}
		if (n == 1 || n ==2 || n ==3)
		{
			if (event.motion.x >= 245 && event.motion.x <= 385 && event.motion.y >= 235 && event.motion.y <= 285)
			{
				n = 0;
			}
		}
		if (n == 1)
		{
			if (event.motion.x >= 15 && event.motion.x <= 380 && event.motion.y >= 75 && event.motion.y <= 125)
			{
				i = 1;
				cout << "Enter username" << endl;			
			}
			if (event.motion.x >= 15 && event.motion.x <= 380 && event.motion.y >= 175 && event.motion.y <= 225)
			{
				i = 2;
				cout << "Enter password" << endl;
			}
			if (event.motion.x >= 15 && event.motion.x <= 155 && event.motion.y >= 235 && event.motion.y <= 285)
			{
				login();
			}
		}
		if (n == 2)
		{
			if (event.motion.x >= 15 && event.motion.x <= 380 && event.motion.y >= 75 && event.motion.y <= 125)
			{
				i = 1;
				cout << "Enter username" << endl;
			}
			if (event.motion.x >= 15 && event.motion.x <= 380 && event.motion.y >= 175 && event.motion.y <= 225)
			{
				i = 2;
				cout << "Enter password" << endl;
			}
			if (event.motion.x >= 15 && event.motion.x <= 155 && event.motion.y >= 235 && event.motion.y <= 285)
			{
				cout << "OK" << endl;
				Register();
			}
		}
	}
}