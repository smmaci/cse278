#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main (int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    QLabel *label = new QLabel("Hello QT!");
    QPushButton *button = new QPushButton("Quit!");
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, SIGNAL(clicked()),&app,SLOT(quit()));

    window->setLayout(layout);
    window->show();
    return app.exec();
 }
