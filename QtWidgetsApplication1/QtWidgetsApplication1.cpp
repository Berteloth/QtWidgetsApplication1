
#include "QtWidgetsApplication1.h"
#include <iostream>
#include <QMessageLogger>
#include <vector>
#include <utility>
#include <algorithm>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setupUI();
}

MainWindow::~MainWindow()
{
    delete m_buttonsLayout1;
    delete m_leftVLayout;
    delete m_middleVLayout;
    delete m_buttonsLayout2;
    delete m_rightVLayout;
    delete m_mainLayout;
    delete m_centralWidget;

}

void MainWindow::setGeo()
{
    m_add->setGeometry(QRect(QPoint(5, 3), QSize(77, 23)));
    m_delete->setGeometry(QRect(QPoint(6, 1), QSize(77, 23)));
    m_update->setGeometry(QRect(QPoint(7, 2), QSize(77, 23)));
    m_filter->setGeometry(QRect(QPoint(8, 3), QSize(77, 23)));
}

void MainWindow::onUpdateButton()
{
    QMessageBox::information(this, "Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onFilterButton()
{
    QMessageBox::information(this, "Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onDeleteButton()
{

    //m_songList.erase(next(m_songList.begin()));
    if (!m_listSongs->selectedItems().empty()) {
        int n = m_listSongs->currentIndex().row();
        qDebug() << n;
        m_songList.erase(std::find(m_songList.begin(), m_songList.end(), m_songList[n]));
        m_listSongs->takeItem(m_listSongs->row(m_listSongs->selectedItems()[0]));
        m_listSongs->takeItem(m_listSongs->row(m_listSongs->selectedItems()[0]));
    }
    else  QMessageBox::information(this, "Message", "Select a song!", QMessageBox::Ok);

}

void MainWindow::onMiddleButton()
{
    qDebug("3092rj0293r");
    if(!m_listSongs->selectedItems().empty())
        m_listPlaylist->addItem(m_listSongs->item(m_listSongs->row(m_listSongs->selectedItems()[0]))->text());
    else QMessageBox::information(this, "Message", "Select a song!", QMessageBox::Ok);
}


void MainWindow::setupUI()
{
    m_centralWidget = new QWidget();
    m_leftVLayout = new QVBoxLayout();

    m_listSongsLabel = new QLabel("All songs:");
    m_listSongs = new QListWidget();

    m_leftFormLayout = new QFormLayout();

    m_titleLable = new QLabel("Title:");
    m_titleText = new QLineEdit();

    m_artistLable = new QLabel("Artist:");
    m_artistText = new QLineEdit();

    m_durationLable = new QLabel("Duration:");
    m_durationText = new QLineEdit();

    m_linkLable = new QLabel("Link:");
    m_linkText = new QLineEdit();

    m_leftFormLayout->addRow(m_titleLable, m_titleText);
    m_leftFormLayout->addRow(m_artistLable, m_artistText);
    m_leftFormLayout->addRow(m_durationLable, m_durationText);
    m_leftFormLayout->addRow(m_linkLable, m_linkText);

    m_leftVLayout->addWidget(m_listSongsLabel);
    m_leftVLayout->addWidget(m_listSongs);
   

    //m_centralWidget->setLayout(m_leftVLayout);
    //this->setCentralWidget(m_centralWidget);

    m_buttonsLayout1 = new QHBoxLayout;
    m_buttonsLayout2 = new QHBoxLayout;

    m_add = new QPushButton("Add");
    m_add->setFixedSize(QSize(77,23));
    
    //connect(m_add, SIGNAL(clicked()), this, SLOT(exit_app()));
    QObject::connect(m_add, &QPushButton::released, this, &MainWindow::onAddButton);
    m_buttonsLayout1->addWidget(m_add);
    



    m_delete = new QPushButton("Delete");
    m_delete->setFixedSize(QSize(77, 23));
    QObject::connect(m_delete, &QPushButton::released, this, &MainWindow::onDeleteButton);
    m_buttonsLayout1->addWidget(m_delete);

    

    m_update = new QPushButton("Update");
    m_update->setFixedSize(QSize(77, 23));
    QObject::connect(m_update, &QPushButton::released, this, &MainWindow::onUpdateButton);
    m_buttonsLayout1->addWidget(m_update);

    

    m_filter = new QPushButton("Filter");
    m_filter->setFixedSize(QSize(77, 23));
    m_leftVLayout->addLayout(m_leftFormLayout);
    m_leftVLayout->addLayout(m_buttonsLayout1);
    QObject::connect(m_filter, &QPushButton::released, this, &MainWindow::onFilterButton);
    m_leftVLayout->addWidget(m_filter, 0, Qt::AlignCenter);
    
    
    //m_leftFormLayout->addRow(m_add, m_delete);
    //m_leftFormLayout->addRow(m_update, m_filter);

    // middle layout
    m_middleVLayout = new QVBoxLayout();
    m_middleFormLayout = new QFormLayout();

    m_toPlaylistButton = new QPushButton(">");
    m_toPlaylistButton->setFixedSize(QSize(77, 23));
    QObject::connect(m_toPlaylistButton, &QPushButton::released, this, &MainWindow::onMiddleButton);

    m_middleVLayout->addWidget(m_toPlaylistButton, 0,Qt::AlignVCenter);
    m_middleVLayout->addLayout(m_middleFormLayout);

    // right layout
    m_rightVLayout = new QVBoxLayout();
    m_rightFormLayout = new QFormLayout();

    m_listPlaylistLabel = new QLabel("Playlist:");
    m_listPlaylist = new QListWidget();

   

    m_rightVLayout->addWidget(m_listPlaylistLabel);
    m_rightVLayout->addWidget(m_listPlaylist);
    m_rightVLayout->addLayout(m_rightFormLayout);


    m_play = new QPushButton("Play");
    //m_play->setFixedSize(QSize(77, 23));
    m_next = new QPushButton("Next");
    //m_next->setFixedSize(QSize(77, 23));
    //m_rightFormLayout->addRow(m_listPlaylistLabel, m_listPlaylist);
    m_mainLayout = new QHBoxLayout;

    m_buttonsLayout2->addWidget(m_play);
    m_buttonsLayout2->addWidget(m_next);


   
    m_mainLayout->addLayout(m_leftVLayout);
    m_mainLayout->addLayout(m_middleVLayout);

    m_rightVLayout->addLayout(m_buttonsLayout2);
    
    m_mainLayout->addLayout(m_rightVLayout);
    m_centralWidget->setLayout(m_mainLayout);
    this->setCentralWidget(m_centralWidget);
    
}

void MainWindow::onAddButton() {
    qDebug() << "afngi";
    QString title = m_titleText->text();
    QString artist = m_artistText->text();

    QString duration = m_durationText->text();
    QString link = m_linkText->text();

    if (title.isEmpty() or artist.isEmpty() or duration.isEmpty() or link.isEmpty())
        QMessageBox::information(this, "Message", "Fill in the label!", QMessageBox::Ok);
    else {
        char* p = strtok((char*)&duration, ":., ");
        std::pair<int, int> test;
        for (int i = 0; i < strlen(p); i++) {
            test.first = (int)p[i];
        }

        p = strtok(NULL, ":., ");

        if (p != NULL) {
            for (int i = 0; i < strlen(p); i++) {
                test.second = (int)p[i];

            }
        }

        m_songList.push_back(Song(title.toStdString(), artist.toStdString(), test, link.toStdString()));

       m_listSongs->addItem("Song: " + m_titleText->text() + " || made by " + m_artistText->text() + " || of duration " + m_durationText->text() + " || Link: " + m_linkText->text());
       // m_listSongs->addItem("Link: " + m_linkText->text());
        
            
    }
}
