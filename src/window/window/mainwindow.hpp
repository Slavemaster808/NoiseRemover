#pragma once

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QtWidgets>

#if 0
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);

 protected:
  void dragEnterEvent(QDragEnterEvent* event) override;
  void dropEvent(QDropEvent* event) override;

 private slots:
  void handleFile(const QString& filePath);

 private:
  QPushButton* m_uploadButton;
  QPushButton* m_downloadButton;
  QProgressBar* m_progressBar;
  QLabel* m_titleLabel;
  QLabel* m_previewLabel;
  QVideoWidget* m_videoWidget;
  QMediaPlayer* m_mediaPlayer;
};

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);

 protected:
  void dragEnterEvent(QDragEnterEvent* event) override;
  void dropEvent(QDropEvent* event) override;

 private slots:
  void handleFile(const QString& filePath);
  void onUploadClicked();

 private:
  QPushButton* m_uploadButton;
  QPushButton* m_downloadButton;
  QProgressBar* m_progressBar;
  QLabel* m_titleLabel;
  QLabel* m_fileNameLabel;  // Новая метка для отображения имени файла
  QMediaPlayer* m_mediaPlayer;
};
#endif

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);

 protected:
  void dragEnterEvent(QDragEnterEvent* event) override;
  void dropEvent(QDropEvent* event) override;
  void resizeEvent(QResizeEvent* event) override;

 private slots:
  void handleFile(const QString& filePath);
  void onUploadClicked();

 private:
  QPushButton* m_uploadButton;
  QPushButton* m_processButton;
  QProgressBar* m_progressBar;
  QLabel* m_titleLabel;
  QLabel* m_fileNameLabel;  // Будет отображать только имя файла
  QMediaPlayer* m_mediaPlayer;
};