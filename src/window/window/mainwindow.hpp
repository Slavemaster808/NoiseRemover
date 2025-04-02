#pragma once

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QtWidgets/QtWidgets>

// namespace Ui {
// class MainWindow;
// }

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);

 private slots:
  void openFileDialog();  // Метод для открытия проводника

 private:
  QPushButton* m_uploadButton;
  QPushButton* m_downloadButton;
  QProgressBar* m_progressBar;
  QLabel* m_titleLabel;
};