#include <QApplication>
#include <window/mainwindow.hpp>

// #include <QtWidgets/QtWidgets>

// int main(int argc, char** argv)
// {
//     QApplication app{argc, argv};

//     QWidget window;
//     window.setWindowFlag(Qt::FramelessWindowHint);
//     window.resize(250, 150);
//     window.move(300, 300);
//     window.setWindowTitle("Hello Qt");
//     window.show();

//     auto l = new QVBoxLayout();

//     auto le = new QLineEdit("");
//     l->addWidget(le);

//     auto b = new QPushButton("Click me");
//     b->setStyleSheet("background-color: #4CAF50; color: white; font-weight:
//     bold; font-size: 16px; border-radius: 8px;"); QObject::connect(b,
//     &QPushButton::clicked, [=]() {
//         if (le->text() == "Егор пидарас")
//             QMessageBox::critical(nullptr, "", "Да");
//     });
//     l->addWidget(b);

//     window.setLayout(l);

//     return app.exec();
// }

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();
// }

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MainWindow window;
  window.setWindowTitle("Noise Remover");
  window.resize(400, 300);
  window.show();

  return app.exec();
}