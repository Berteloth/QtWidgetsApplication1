#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setGeo();
private:
    void setupUI();

    QHBoxLayout* m_mainLayout;
    QHBoxLayout* m_buttonsLayout1;
    QHBoxLayout* m_buttonsLayout2;


    QWidget* m_centralWidget;
    QVBoxLayout* m_leftVLayout;
    QFormLayout* m_leftFormLayout;

    // form layout
    QLabel* m_titleLable;
    QLineEdit* m_titleText;

    QLabel* m_artistLable;
    QLineEdit* m_artistText;

    QLabel* m_durationLable;
    QLineEdit* m_durationText;

    QLabel* m_linkLable;
    QLineEdit* m_linkText;

    QLabel* m_listSongsLabel;
    QTextEdit* m_listSongs;

    QPushButton* m_add;
    QPushButton* m_delete;
    QPushButton* m_update;
    QPushButton* m_filter;

    // middle layout
    QVBoxLayout* m_middleVLayout;
    QFormLayout* m_middleFormLayout;

    //form layout
    QPushButton* m_toPlaylistButton;

    // right layout
    QVBoxLayout* m_rightVLayout;
    QFormLayout* m_rightFormLayout;
    
    //form layout
    QLabel* m_listPlaylistLabel;
    QTextEdit* m_listPlaylist;

    QPushButton* m_play;
    QPushButton* m_next;
};
