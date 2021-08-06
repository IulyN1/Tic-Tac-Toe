#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qbuttongroup.h>

class GUI : public QWidget
{
private:
	QPushButton* btnPlay = new QPushButton{ "Play" };
	QLabel* result = new QLabel{ "Result:" };
	QPushButton* btn1 = new QPushButton;
	QPushButton* btn2 = new QPushButton;
	QPushButton* btn3 = new QPushButton;
	QPushButton* btn4 = new QPushButton;
	QPushButton* btn5 = new QPushButton;
	QPushButton* btn6 = new QPushButton;
	QPushButton* btn7 = new QPushButton;
	QPushButton* btn8 = new QPushButton;
	QPushButton* btn9 = new QPushButton;
	QButtonGroup* btns = new QButtonGroup;

	// Function that initializes the GUI components
	void initGui();

	// Function that connects the signals of the GUI components
	void connectSignals();

	// Function that sets the initial state of the GUI application
	void setInitialState();

	// Function that prepares the app state for the game start
	void prepareStart();

	// Function that computes the Tic Tac Toe logic
	// btn - pointer to QPushButton
	void ticTac(QPushButton* btn);
public:
	GUI() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

