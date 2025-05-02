#include <window/mainwindow.hpp>

// MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
//   m_titleLabel =
//       new QLabel("<h1 style='color:#3498db'>Noise Remover</h1>", this);
//   m_titleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

//   m_uploadButton = new QPushButton("Upload File", this);
//   m_uploadButton->setAcceptDrops(true);  // Разрешается перетаскивание
//   connect(
//       m_uploadButton,
//       &QPushButton::clicked,
//       this,
//       &MainWindow::onUploadClicked);

//   m_downloadButton = new QPushButton("Download File", this);
//   m_downloadButton->hide();  // Скрываем кнопку Download изначально

//   m_progressBar = new QProgressBar(this);
//   m_progressBar->setRange(0, 100);

//   m_fileNameLabel = new QLabel("", this);  // Будем выводить только имя файла
//   m_fileNameLabel->setWordWrap(
//       true);  // Переключатель переноса текста на новую строку

//   m_mediaPlayer = new QMediaPlayer(this);

//   QVBoxLayout* layout = new QVBoxLayout(this);
//   layout->addWidget(m_titleLabel);
//   layout->addWidget(m_uploadButton);
//   layout->addWidget(m_fileNameLabel);
//   layout->addWidget(m_downloadButton);
//   layout->addWidget(m_progressBar);

//   setLayout(layout);

//   // Всё окно принимает перетаскивание
//   setAcceptDrops(true);
// }

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

  // Прямо устанавливаем стили кнопкам
  m_uploadButton->setStyleSheet(R"(
    QPushButton {
      background-color: #3498db;  /* Голубой фон */
      color: white;                /* Белый текст */
      font-size: 16px;             /* Размер шрифта */
      padding: 10px 20px;          /* Внутренние отступы */
      border-radius: 5px;          /* Скругленные углы */
      min-width: 150px;            /* Минимальная ширина */
      height: 40px;                /* Высота */
      font-family: 'Arial';        /* Семейство шрифтов */
    }

    QPushButton:pressed {
      background-color: #2980b9;   /* Темно-голубой при нажатии */
    }
  )");

  m_downloadButton = new QPushButton("Download File", this);
  m_downloadButton->hide();  // Скрываем кнопку Download изначально

  // То же самое для второй кнопки
  m_downloadButton->setStyleSheet(R"(
    QPushButton {
      background-color: #3498db;  /* Голубой фон */
      color: white;                /* Белый текст */
      font-size: 16px;             /* Размер шрифта */
      padding: 10px 20px;          /* Внутренние отступы */
      border-radius: 5px;          /* Скругленные углы */
      min-width: 150px;            /* Минимальная ширина */
      height: 40px;                /* Высота */
      font-family: 'Arial';        /* Семейство шрифтов */
    }

    QPushButton:pressed {
      background-color: #2980b9;   /* Темно-голубой при нажатии */
    }
  )");

  // m_progressBar = new QProgressBar(this);
  // m_progressBar->setRange(0, 100);

  m_fileNameLabel = new QLabel("", this);  // Будет отображать только имя файла
  m_fileNameLabel->setWordWrap(
      true);  // Возможность переноса текста на новую строку

  m_mediaPlayer = new QMediaPlayer(this);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(m_titleLabel);
  layout->addWidget(m_uploadButton);
  layout->addWidget(m_fileNameLabel);
  layout->addWidget(m_downloadButton);
  // layout->addWidget(m_progressBar);

  setLayout(layout);

  // Всё окно принимает перетаскивание
  setAcceptDrops(true);
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
    return;
  }

  // Сохраняем только имя файла без пути
  QString filenameOnly = fi.fileName();
  m_fileNameLabel->setText(filenameOnly);
  m_downloadButton->show();  // Покажем кнопку Download после успешной загрузки

  // Игнорируем обработку плейера, если она не нужна
  /* m_mediaPlayer->stop();
  m_mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
  m_mediaPlayer->play(); */
}