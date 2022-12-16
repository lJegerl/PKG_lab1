#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <convert.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_activated(int index);
    void on_comboBox_2_activated(int index);
    void write_colors(int index, QColor color);

    int get_index();
    void set_index(int index);
    int get_index_2();
    void set_index_2(int index);
    QColor get_color();

    void set_color(QColor color);
    void draw_current_color(QColor color);

    void check_rgb(int number, QColor color);
    void check_cmyk(int number, QColor color);
    void check_hls(int number, QColor color);
    void check_lab(int number, QColor color);
    void check_xyz(int number, QColor color);
    void check_hsv(int number, QColor color);

    void convert_rgb();
    void convert_cmyk();
    void convert_hls();
    void convert_lab();
    void convert_xyz();
    void convert_hsv();

    void clear_lineEdits();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    int index = 0;
    int index_2 = 0;
    QColor color_;
    bool trigger = true;
};
#endif // MAINWINDOW_H
