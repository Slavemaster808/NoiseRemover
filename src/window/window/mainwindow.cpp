#include <window/mainwindow.hpp>

#if 0
MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  m_titleLabel =
      new QLabel("<h1 style='color:#3498db'>Noise Remover</h1>", this);
  m_titleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

  m_uploadButton = new QPushButton("Upload File", this);
  m_uploadButton->setAcceptDrops(true);  // Разрешается перетаскивание
  connect(
      m_uploadButton,
      &QPushButton::clicked,
      this,
      &MainWindow::onUploadClicked);

  m_processButton = new QPushButton("Download File", this);
  m_processButton->hide();  // Скрываем кнопку Download изначально

  m_progressBar = new QProgressBar(this);
  m_progressBar->setRange(0, 100);

  m_fileNameLabel = new QLabel("", this);  // Будем выводить только имя файла
  m_fileNameLabel->setWordWrap(
      true);  // Переключатель переноса текста на новую строку

  m_mediaPlayer = new QMediaPlayer(this);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(m_titleLabel);
  layout->addWidget(m_uploadButton);
  layout->addWidget(m_fileNameLabel);
  layout->addWidget(m_processButton);
  layout->addWidget(m_progressBar);

  setLayout(layout);

  // Всё окно принимает перетаскивание
  setAcceptDrops(true);
}
#endif

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  QPixmap bkgnd(":/images/background-image/background.jpg");
  bkgnd = bkgnd.scaled(
      this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  QPalette palette;
  palette.setBrush(QPalette::Window, bkgnd);
  this->setPalette(palette);
  this->setAutoFillBackground(true);

  // Главный контейнер для всех элементов
  QWidget* mainBlock = new QWidget(this);
  mainBlock->setStyleSheet(
      "background-color: rgba(240, 240, 240, 0.85);"
      "border-radius: 10px;"
      "border: 2px solid #3498db;"
      "padding: 30px;");
  mainBlock->setFixedWidth(400);

  // Название приложения (вверху окна)
  m_titleLabel = new QLabel(this);
  m_titleLabel->setText(
      "<h1 style='color:#000000; text-shadow: 1px 1px 2px #000000;'>Noise "
      "Remover</h1>");
  m_titleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
  m_titleLabel->setStyleSheet("margin: 20px 0; padding: 10px;");

  // Кнопка Upload
  m_uploadButton = new QPushButton("Upload File", mainBlock);

  // Метка для имени файла
  m_fileNameLabel = new QLabel("", mainBlock);
  m_fileNameLabel->setStyleSheet(
      "color: #2c3e50;"
      "font-size: 14px;"
      "background-color: rgba(255, 255, 255, 0.7);"
      "padding: 10px;"
      "border-radius: 4px;"
      "margin: 15px 0;"
      "border: 1px solid #d6d6d6;");
  m_fileNameLabel->setAlignment(Qt::AlignCenter);
  m_fileNameLabel->setWordWrap(true);
  m_fileNameLabel->setFixedWidth(340);

  // Кнопка Download (изначально скрыта)
  m_processButton = new QPushButton("Process File", mainBlock);
  m_processButton->hide();

  // Стиль для кнопок
  QString buttonStyle = R"(
      QPushButton {
          background-color: #3498db;
          color: white;
          font-size: 16px;
          padding: 12px 0;
          border-radius: 6px;
          width: 200px;
          min-height: 45px;
          font-family: 'Arial';
          border: none;
      }
      QPushButton:hover {
          background-color: #2980b9;
          box-shadow: 0 2px 4px rgba(0,0,0,0.2);
      }
      QPushButton:pressed {
          background-color: #1a6ea0;
      }
  )";

  m_uploadButton->setStyleSheet(buttonStyle);
  m_processButton->setStyleSheet(buttonStyle);

  // Вертикальный layout для элементов внутри блока
  QVBoxLayout* blockLayout = new QVBoxLayout(mainBlock);
  blockLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  blockLayout->setSpacing(10);

  // Добавляем элементы в правильном порядке
  blockLayout->addWidget(m_uploadButton, 0, Qt::AlignHCenter);
  blockLayout->addWidget(m_fileNameLabel, 0, Qt::AlignHCenter);
  blockLayout->addWidget(m_processButton, 0, Qt::AlignHCenter);
  blockLayout->addStretch();  // Растягиваем оставшееся пространство

  // Главный layout окна
  QVBoxLayout* mainLayout = new QVBoxLayout(this);
  mainLayout->setContentsMargins(0, 0, 0, 20);
  mainLayout->addWidget(m_titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);

  // Центрируем основной блок по горизонтали
  QHBoxLayout* hLayout = new QHBoxLayout();
  hLayout->addStretch();
  hLayout->addWidget(mainBlock);
  hLayout->addStretch();

  mainLayout->addLayout(hLayout, 1);  // Блок растягивается по вертикали
  mainLayout->setSpacing(0);

  // Остальные настройки
  setAcceptDrops(true);
  connect(
      m_uploadButton,
      &QPushButton::clicked,
      this,
      &MainWindow::onUploadClicked);

  // Установка минимального размера окна
  setMinimumSize(600, 500);
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event) {
  if (event->mimeData()->hasUrls())
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent* event) {
  const QMimeData* mimeData = event->mimeData();
  if (mimeData->hasUrls()) {
    QList<QUrl> urlList = mimeData->urls();
    if (!urlList.isEmpty()) {
      QString filePath = urlList.first().toLocalFile();
      handleFile(filePath);
    }
  }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  QWidget::resizeEvent(event);

  QPixmap bkgnd(":/images/background-image/background.jpg");
  bkgnd = bkgnd.scaled(
      this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  int blockHeight = height() - 120;  // 120px - место для заголовка и
  if (blockHeight > 250) {  // Минимальная высота 250px
    findChild<QWidget*>()->setFixedHeight(blockHeight);
  }

  QPalette palette;
  palette.setBrush(QPalette::Window, bkgnd);
  this->setPalette(palette);
}

void MainWindow::onUploadClicked() {
  QString filePath = QFileDialog::getOpenFileName(
      this,
      tr("Open File"),
      "",
      tr("Audio or Video (*.mp3 *.mp4)")  // Ограничиваемся этими расширениями
  );
  if (!filePath.isEmpty()) {
    handleFile(filePath);
  }
}

void MainWindow::handleFile(const QString& filePath) {
  QFileInfo fi(filePath);
  QString extension = fi.suffix().toLower();

  if (extension != "mp3" &&
      extension != "mp4") {  // Проверка допустимых форматов
    m_fileNameLabel->setText(tr("Unsupported format of the file."));
    m_processButton->hide();
    return;
  }

  // Сохраняем только имя файла без пути
  QString filenameOnly = fi.fileName();
  m_fileNameLabel->setText(filenameOnly);
  m_processButton->show();  // Покажем кнопку Download после успешной загрузки

  // Игнорируем обработку плейера, если она не нужна
  /* m_mediaPlayer->stop();
  m_mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
  m_mediaPlayer->play(); */
}