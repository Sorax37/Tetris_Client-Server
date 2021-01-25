#pragma once
#pragma warning(disable:4996)

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <winsock2.h>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include "gameWindow.h"
//using std::string;

using namespace std;

//string playerName;
const int M = 20;
const int N = 10;
int score = 0;

int field[M][N] = { 0 };

struct newPoint
{
	int x, y;
} a[4], b[4], c[4];

int figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x])
		{
			return 0;
		}

	return 1;
};

bool checkGameOver()
{
	for (int i = 0; i < 4; i++)
		if (a[i].y < 1) return 1;
	return 0;
}

void endGame()
{
	for (int i = 0; i < N; i++)
	{
		if (field[1][i])
		{
			std::string test1 = std::to_string(score);
			MessageBoxA(NULL, test1.c_str(), "GAME OVER", MB_OK);
		}
	}
}





namespace CLRTetris {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace sf;
    using namespace std;

	/// <summary>
	/// Сводка для menuWindow
	/// </summary>
	public ref class menuWindow : public System::Windows::Forms::Form
	{
	public:
		menuWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~menuWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;






    protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button1->Location = System::Drawing::Point(160, 198);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(171, 61);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Start game";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &menuWindow::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(167, 92);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(164, 29);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Your nickname:";
            // 
            // textBox1
            // 
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox1->Location = System::Drawing::Point(160, 134);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(171, 36);
            this->textBox1->TabIndex = 2;
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button2->Location = System::Drawing::Point(134, 276);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(220, 61);
            this->button2->TabIndex = 3;
            this->button2->Text = L"The leader\'s board";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &menuWindow::button2_Click);
            // 
            // button3
            // 
            this->button3->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button3->Location = System::Drawing::Point(186, 352);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(116, 61);
            this->button3->TabIndex = 4;
            this->button3->Text = L"Exit";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &menuWindow::button3_Click);
            // 
            // menuWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(523, 450);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Name = L"menuWindow";
            this->Text = L"Menu";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

        msclr::interop::marshal_context context;
        std::string playerName = context.marshal_as<std::string>(textBox1->Text);

        playerName += " ";

        WORD ver = MAKEWORD(2, 2);
        WSADATA wsaData;
        int retVal = 0;
        WSAStartup(ver, (LPWSADATA)&wsaData);
        LPHOSTENT hostEnt;
        hostEnt = gethostbyname("localhost");
        if (!hostEnt)
        {
            WSACleanup();
        }
        //Создаем сокет
        int clientSock = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSock == SOCKET_ERROR)
        {
            WSACleanup();
        }
        SOCKADDR_IN serverInfo;
        serverInfo.sin_family = AF_INET;
        serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
        serverInfo.sin_port = htons(8080);
        retVal = connect(clientSock, (struct sockaddr*)&serverInfo, sizeof(serverInfo));
        if (retVal == SOCKET_ERROR)
        {
            WSACleanup();
        }
        srand(time(0));

        RenderWindow window(VideoMode(320, 480), "The Game");

        sf::Font font;
        font.loadFromFile("Ranchers-Regular.ttf");

        sf::Text textScore("", font, 30);
        textScore.setColor(sf::Color::Magenta);

        /////переменная скорости/////
        sf::Text textDelay("", font, 30);
        textScore.setColor(sf::Color::Magenta);
        /////переменная скорости/////

        Texture t1, t2, t3;
        t1.loadFromFile("Debug/tiles.png");
        t2.loadFromFile("Debug/background5.jpg");
        t3.loadFromFile("Debug/frame2.png");

        Sprite s(t1), s1(t1), background(t2), frame(t3);

        int dx = 0; bool rotate = 0; int colorNum = 1 + rand() % 7;
        int nextColor = 1 + rand() % 7;
        bool beginGame = true;
        int arrayFigures[2];
        int arrayColors[2];
        float timer = 0, delay = 1;

        Clock clock;

        while (window.isOpen())
        {
            //string playerName = textBox1->Text;

            textScore.setString("Score: ");
            textScore.setPosition(10, 400);

            /////переменная скорости/////
            textDelay.setString("Difficulty: ");
            textDelay.setPosition(10, 430);

            arrayFigures[0] = arrayFigures[1];
            arrayColors[0] = arrayColors[1];

            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) {
                    window.close();
                    closesocket(clientSock);
                    WSACleanup();
                    score = 0;
                    for (int k = 0; k < M; k++) {
                        for (int l = 0; l < N; l++) {
                            field[k][l] = false;
                        }
                    }
                    field[M][N] = { 0 };
                    arrayFigures[0] = arrayFigures[1] = NULL;
                    arrayColors[0] = arrayColors[1] = NULL;
                    beginGame = true;
                    timer = 0;
                    delay = 1;
                    window.close();
                    window.clear();
                }

                if (e.type == Event::KeyPressed)
                    if (e.key.code == Keyboard::Up) rotate = true;
                    else if (e.key.code == Keyboard::Left) dx = -1;
                    else if (e.key.code == Keyboard::Right) dx = 1;
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

            //// движение влево и вправо///
            for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
            if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

            //////поворот фигур//////
            if (rotate)
            {
                newPoint p = a[1]; //центр поворота
                for (int i = 0; i < 4; i++)
                {
                    int x = a[i].y - p.y;
                    int y = a[i].x - p.x;
                    a[i].x = p.x - x;
                    a[i].y = p.y + y;
                }
                if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
            }

            ///////таймер//////
            if (timer > delay)
            {
                for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

                if (!check())
                {
                    for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
                    nextColor = 1 + rand() % 7;//цвет следующей фигуры
                    arrayColors[1] = nextColor;
                    colorNum = arrayColors[0]; //цвет текущей фигуры
                    int n = arrayFigures[0]; // переменная определения вида текущей фигуры
                    int nextFigure = rand() % 7; // переменная определения вида следующей фигуры
                    arrayFigures[1] = nextFigure;
                    for (int i = 0; i < 4; i++)
                    {
                        a[i].x = figures[n][i] % 2 + 4;
                        a[i].y = figures[n][i] / 2;
                        c[i].x = figures[arrayFigures[1]][i] % 2 + 4;
                        c[i].y = figures[arrayFigures[1]][i] / 2;
                    }
                }

                timer = 0;

                for (int i = 0; i < N; i++) //проверка на конец игры
                {
                    if (field[1][i])
                    {
                        std::string test1 =  "Your score: " + std::to_string(score);
                        MessageBoxA(NULL, test1.c_str(), "GAME OVER", MB_OK);
                        //отправка данных о счете на сервер
                        string strScore = to_string(score);
                        string nameResult = playerName + strScore;
                        const char* pBuf = nameResult.c_str();
                        retVal = send(clientSock, pBuf, strlen(pBuf), 0);
                        char leaderBoard[2048];
                        recv(clientSock, leaderBoard, sizeof(leaderBoard), 0);
                        if (retVal == SOCKET_ERROR)
                        {
                            //label2->Text = Convert::ToString("Ошибка при отправке");
                            WSACleanup();
                        }
                        closesocket(clientSock);
                        WSACleanup();
                        score = 0;
                        for (int k = 0; k < M; k++) {
                            for (int l = 0; l < N; l++) {
                                field[k][l] = false;
                            }
                        }
                        field[M][N] = { 0 };
                        arrayFigures[0] = arrayFigures[1] = NULL;
                        arrayColors[0] = arrayColors[1] = NULL;
                        beginGame = true;
                        timer = 0;
                        delay = 1;
                        window.close();
                        window.clear();
                    }
                }

            }

            if (beginGame) // объявление типа фигуры для начала игры
            {
                beginGame = false;
                int n = rand() % 7; //переменная определения вида фигуры
                arrayFigures[0] = n;
                int nextFigure = rand() % 7;
                arrayFigures[1] = nextFigure;
                colorNum = 1 + rand() % 7;
                arrayColors[0] = colorNum;
                nextColor = 1 + rand() % 7;
                arrayColors[1] = nextColor;
                for (int i = 0; i < 4; i++)
                {
                    a[i].x = figures[n][i] % 2 + 4;
                    a[i].y = figures[n][i] / 2;
                    c[i].x = figures[arrayFigures[1]][i] % 2 + 4;
                    c[i].y = figures[arrayFigures[1]][i] / 2;
                }
                
            }
            dx = 0; rotate = 0;

            ///////проверка линий//////////
            int k = M - 1;
            int countFilledLines = 1;
            for (int i = M - 1; i > 0; i--)
            {
                int count = 0;

                for (int j = 0; j < N; j++)
                {
                    if (field[i][j]) count++;
                    field[k][j] = field[i][j];
                }
                if (count < N)
                {
                    countFilledLines = 1;
                    k--;
                }
                else
                {
                    score += countFilledLines * 100;
                    countFilledLines += 1;
                }
            }

            dx = 0;
            rotate = 0;
            //delay - скорость падения фигур (уровень сложности) 1(медленная) 0.5(быстрая)
            
            delay = (1000 / ((float)score + 1000)) + 0.03; //[0.03, 1] 1->0.03 при росте счета

            /////////отрисовка//////////
            window.clear(sf::Color::White);
            window.draw(background);

            for (int i = 0; i < M; i++) //код отрисовки текущей фигуры после падения
                for (int j = 0; j < N; j++)
                {
                    if (field[i][j] == 0) continue;
                    s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                    s.setPosition(j * 18, i * 18);
                    s.move(28, 31); //стабилизация фигуры
                    window.draw(s);
                }

            for (int i = 0; i < 4; i++) //код отрисовки текущей фигуры во время падения
            {
                s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                s.setPosition(a[i].x * 18, a[i].y * 18);
                s.move(28, 31); //стабилизация фигуры
                window.draw(s);
            }
            
            /////код отрисовки следующей фигуры/////
            for (int i = 0; i < 4; i++)
            {
                s.setTextureRect(IntRect(nextColor * 18, 0, 18, 18));
                s.setPosition(c[i].x * 18, c[i].y * 18);
                if (arrayFigures[1] == 0) { //стабилизация фигуры
                    s.move(172, 33);
                }
                else if (arrayFigures[1] == 6) {
                    s.move(180, 35);
                }
                else {
                    s.move(180, 25); 
                }
                window.draw(s);
            }

            std::ostringstream playerScoreString;
            playerScoreString << score;
            textScore.setString("Score: " + playerScoreString.str());

            /////переменная скорости/////
            std::ostringstream playerDelay;
            if ((round((1 / delay) * 100) / 100) == 0.97) {
                playerDelay << 0;
            }
            else {
                playerDelay << (round((1 / delay) * 100) / 100) - 1;
            }
            textDelay.setString("Difficulty: " + playerDelay.str());
            window.draw(textDelay);
            /////переменная скорости/////

            window.draw(textScore);
            window.draw(frame);
            window.display();
            
        }
	}

    //комментарий
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    WORD ver = MAKEWORD(2, 2);
    WSADATA wsaData;
    int retVal = 0;
    WSAStartup(ver, (LPWSADATA)&wsaData);
    LPHOSTENT hostEnt;
    hostEnt = gethostbyname("localhost");
    if (!hostEnt)
    {
        WSACleanup();
    }
    //Создаем сокет
    int clientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSock == SOCKET_ERROR)
    {
        WSACleanup();
    }
    SOCKADDR_IN serverInfo;
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverInfo.sin_port = htons(8080);
    retVal = connect(clientSock, (struct sockaddr*)&serverInfo, sizeof(serverInfo));
    if (retVal == SOCKET_ERROR)
    {
        WSACleanup();
    }
    char leaderBoard[1024] = "";
    retVal = recv(clientSock, leaderBoard, sizeof(leaderBoard), 0);
    System::String^ leaderBoardstr;
    leaderBoardstr = gcnew System::String(leaderBoard);

    gameWindow^ LBwindow = gcnew gameWindow();
    char* pch;
    pch = strtok(leaderBoard, ",");

    string pchstring = (string)pch;
    pchstring.replace(pchstring.find("=>"), 2, "\t\t");
    pchstring.replace(pchstring.find("{"), 1, "");
    pchstring.replace(pchstring.find(34), 1, "");
    pchstring.replace(pchstring.find(34), 1, "");
    strcpy(pch, pchstring.c_str());

    System::String^ pchstr;
    LBwindow->listBox1->Items->Add("PLAYER\t\tSCORE");
    LBwindow->listBox1->Items->Add("");
    while (pch != NULL)
    {
        pchstr = gcnew System::String(pch);
        
        LBwindow->listBox1->Items->Add(pchstr);
        pch = strtok(NULL, " ,");
        if (pch != NULL) {
            pchstring = (string)pch;
            pchstring.replace(pchstring.find("=>"), 2, "\t\t");
            pchstring.replace(pchstring.find(34), 1, "");
            pchstring.replace(pchstring.find(34), 1, "");
            char c = pchstring[pchstring.size() - 1];
            if (c == '}') {
                pchstring.erase(pchstring.size() - 1, 1);
            }
            strcpy(pch, pchstring.c_str());
        }
        
    }

    LBwindow->Show();

    closesocket(clientSock);
    WSACleanup();

}
};
}
