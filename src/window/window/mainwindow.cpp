#include <window/mainwindow.hpp>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  m_titleLabel = new QLabel("<h1>Noise Remover</h1>", this);
  m_titleLabel->setAlignment(Qt::AlignHCenter);

  m_uploadButton = new QPushButton("Upload File", this);
  m_downloadButton = new QPushButton("Download File", this);

  m_progressBar = new QProgressBar(this);
  m_progressBar->setRange(0, 100);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(m_titleLabel);
  layout->addWidget(m_uploadButton);
  layout->addWidget(m_downloadButton);
  layout->addWidget(m_progressBar);

  setLayout(layout);

  // Подключаем сигнал кнопки "Upload File" к слоту openFileDialog
  connect(
      m_uploadButton, &QPushButton::clicked, this, &MainWindow::openFileDialog);
}

void MainWindow::openFileDialog() {
  QString filePath = QFileDialog::getOpenFileName(
      this, tr("Open File"), "", tr("All Files (*.*)"));

  if (!filePath.isEmpty()) {
    QMessageBox::information(this, tr("Selected File"), filePath);
    // Здесь можно добавить обработку выбранного файла
  }
}