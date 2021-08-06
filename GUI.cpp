#include "GUI.h"
#include <qboxlayout.h>
#include <time.h>
#include <qvariant.h>

void GUI::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	QHBoxLayout* lyPlay = new QHBoxLayout;
	lyPlay->addWidget(btnPlay);
	ly->addLayout(lyPlay);

	QHBoxLayout* row1 = new QHBoxLayout;
	row1->addWidget(btn1);
	row1->addWidget(btn2);
	row1->addWidget(btn3);

	QHBoxLayout* row2 = new QHBoxLayout;
	row2->addWidget(btn4);
	row2->addWidget(btn5);
	row2->addWidget(btn6);

	QHBoxLayout* row3 = new QHBoxLayout;
	row3->addWidget(btn7);
	row3->addWidget(btn8);
	row3->addWidget(btn9);

	ly->addLayout(row1);
	ly->addLayout(row2);
	ly->addLayout(row3);
	ly->addWidget(result);
}

void GUI::prepareStart() {
	result->show();
	btn1->show();
	btn2->show();
	btn3->show();
	btn4->show();
	btn5->show();
	btn6->show();
	btn7->show();
	btn8->show();
	btn9->show();
	btn1->setText("");
	btn2->setText("");
	btn3->setText("");
	btn4->setText("");
	btn5->setText("");
	btn6->setText("");
	btn7->setText("");
	btn8->setText("");
	btn9->setText("");
	btn1->setDisabled(false);
	btn2->setDisabled(false);
	btn3->setDisabled(false);
	btn4->setDisabled(false);
	btn5->setDisabled(false);
	btn6->setDisabled(false);
	btn7->setDisabled(false);
	btn8->setDisabled(false);
	btn9->setDisabled(false);
	result->setText("Result:");
}

void GUI::ticTac(QPushButton* btn) {
	if (btn->text() == "") {
		btn->setText("X");

		if (btn1->text() == "X" && btn2->text() == "X" && btn3->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn1->text() == "X" && btn4->text() == "X" && btn7->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn1->text() == "X" && btn5->text() == "X" && btn9->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn2->text() == "X" && btn5->text() == "X" && btn8->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn4->text() == "X" && btn5->text() == "X" && btn6->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn3->text() == "X" && btn6->text() == "X" && btn9->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn3->text() == "X" && btn5->text() == "X" && btn7->text() == "X") {
			result->setText("Result: You won!");
		}
		else if (btn7->text() == "X" && btn8->text() == "X" && btn9->text() == "X") {
			result->setText("Result: You won!");
		}

		if (result->text().length() > 10) {
			btn1->setDisabled(true);
			btn2->setDisabled(true);
			btn3->setDisabled(true);
			btn4->setDisabled(true);
			btn5->setDisabled(true);
			btn6->setDisabled(true);
			btn7->setDisabled(true);
			btn8->setDisabled(true);
			btn9->setDisabled(true);
			return;
		}

		int ct{ 0 };
		for (const auto elem : btns->buttons()) {
			if (elem->text() != "")ct++;
		}
		if (ct == 9) {
			result->setText("Result: Draw!");
			return;
		}

		int num = rand() % 9 + 1;
		auto button = btns->button(num);
		while (button->text() != "") {
			num = rand() % 9 + 1;
			button = btns->button(num);
		}
		button->setText("O");

		if (btn1->text() == "O" && btn2->text() == "O" && btn3->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn1->text() == "O" && btn4->text() == "O" && btn7->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn1->text() == "O" && btn5->text() == "O" && btn9->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn2->text() == "O" && btn5->text() == "O" && btn8->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn4->text() == "O" && btn5->text() == "O" && btn6->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn3->text() == "O" && btn6->text() == "O" && btn9->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn3->text() == "O" && btn5->text() == "O" && btn7->text() == "O") {
			result->setText("Result: You lost!");
		}
		else if (btn7->text() == "O" && btn8->text() == "O" && btn9->text() == "O") {
			result->setText("Result: You lost!");
		}

		if (result->text().length() > 10) {
			btn1->setDisabled(true);
			btn2->setDisabled(true);
			btn3->setDisabled(true);
			btn4->setDisabled(true);
			btn5->setDisabled(true);
			btn6->setDisabled(true);
			btn7->setDisabled(true);
			btn8->setDisabled(true);
			btn9->setDisabled(true);
			return;
		}
	}
}

void GUI::connectSignals() {
	srand(time(NULL));
	connect(btnPlay, &QPushButton::clicked, this, [=]() {
		prepareStart();
		});
	connect(btn1, &QPushButton::clicked, this, [=]() {
		ticTac(btn1);
		});
	connect(btn2, &QPushButton::clicked, this, [=]() {
		ticTac(btn2);
		});
	connect(btn3, &QPushButton::clicked, this, [=]() {
		ticTac(btn3);
		});
	connect(btn4, &QPushButton::clicked, this, [=]() {
		ticTac(btn4);
		});
	connect(btn5, &QPushButton::clicked, this, [=]() {
		ticTac(btn5);
		});
	connect(btn6, &QPushButton::clicked, this, [=]() {
		ticTac(btn6);
		});
	connect(btn7, &QPushButton::clicked, this, [=]() {
		ticTac(btn7);
		});
	connect(btn8, &QPushButton::clicked, this, [=]() {
		ticTac(btn8);
		});
	connect(btn9, &QPushButton::clicked, this, [=]() {
		ticTac(btn9);
		});
}

void GUI::setInitialState() {
	btn1->hide();
	btn2->hide();
	btn3->hide();
	btn4->hide();
	btn5->hide();
	btn6->hide();
	btn7->hide();
	btn8->hide();
	btn9->hide();
	this->setStyleSheet("QPushButton{font-size: 30px;}");
	btns->addButton(btn1, 1);
	btns->addButton(btn2, 2);
	btns->addButton(btn3, 3);
	btns->addButton(btn4, 4);
	btns->addButton(btn5, 5);
	btns->addButton(btn6, 6);
	btns->addButton(btn7, 7);
	btns->addButton(btn8, 8);
	btns->addButton(btn9, 9);
	result->setStyleSheet("QLabel{font-size: 25px;}");
	result->hide();
}