#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"

convert Con;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette;

    palette.setColor(QPalette::Background, Qt::gray);
    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);
    ui->label_2->lower();

    palette.setColor(QPalette::Background, Qt::black);
    ui->label_3->setAutoFillBackground(true);
    ui->label_3->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_current_color(QColor color) {
    QPalette palette;
    palette.setColor(QPalette::Background, color);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(palette);
    ui->label_3->lower();
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor();
    draw_current_color(color);
    clear_lineEdits();
    set_color(color);
    write_colors(get_index(), color);
}

void MainWindow::clear_lineEdits() {
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
}

void MainWindow::on_comboBox_activated(int index)
{
    set_index(index);
    clear_lineEdits();
}

void MainWindow::on_comboBox_2_activated(int index)
{
    set_index(index);
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();

}

void MainWindow::write_colors(int index, QColor color)
{
    if(index == 0) {
        check_rgb(1, color);
        check_lab(2, color);
        check_cmyk(3, color);
        set_color(color);
    }

    else if(index == 1) {
        check_rgb(1, color);
        check_cmyk(2, color);
        check_hls(3, color);
        set_color(color);
    }
    else if(index == 2) {
        check_rgb(1, color);
        check_xyz(2, color);
        check_lab(3, color);
        set_color(color);
    }
    else if(index == 3) {
        check_rgb(1, color);
        check_hsv(2, color);
        check_lab(3, color);
        set_color(color);
    }
    else if(index == 4) {
        check_cmyk(1, color);
        check_lab(2, color);
        check_hsv(3, color);
        set_color(color);
    }
    else if(index == 5) {
        check_cmyk(1, color);
        check_rgb(2, color);
        check_hls(3, color);
        set_color(color);
    }
    else if(index == 6) {
        check_cmyk(1, color);
        check_rgb(2, color);
        check_hsv(3, color);
        set_color(color);
    }
    else if(index == 7) {
        check_rgb(1, color);
        check_xyz(2, color);
        check_hsv(3, color);
        set_color(color);
    }
    else if(index == 8) {
        check_hsv(1, color);
        check_xyz(2, color);
        check_lab(3, color);
        set_color(color);
    }
    else if(index == 9) {
        check_cmyk(1, color);
        check_lab(2, color);
        check_rgb(3, color);
        set_color(color);
    }
    else if(index == 10) {
        check_xyz(1, color);
        check_lab(2, color);
        check_hls(3, color);
        set_color(color);
    }
    else if(index == 11) {
        check_rgb(1, color);
        check_xyz(2, color);
        check_hls(3, color);
        set_color(color);
    }
    else if(index == 12) {
        check_rgb(1, color);
        check_xyz(2, color);
        check_cmyk(3, color);
        set_color(color);
    }
    else if(index == 13) {
        check_cmyk(1, color);
        check_lab(2, color);
        check_xyz(3, color);
        set_color(color);
    }
    else if(index == 14) {
        check_rgb(1, color);
        check_cmyk(2, color);
        check_hsv(3, color);
        set_color(color);
    }
    else if(index == 15) {
        check_cmyk(1, color);
        check_hls(2, color);
        check_xyz(3, color);
        set_color(color);
    }
    else if(index == 16) {
        check_rgb(1, color);
        check_hls(2, color);
        check_lab(3, color);
        set_color(color);
    }
    else if(index == 17) {
        check_cmyk(1, color);
        check_xyz(2, color);
        check_rgb(3, color);
        set_color(color);
    }
}

int MainWindow::get_index() {
    return index;
}

void MainWindow::set_index(int index_) {
    index = index_;
}

int MainWindow::get_index_2()
{
    return index_2;
}

void MainWindow::set_index_2(int index)
{
    index_2 = index;
}

QColor MainWindow::get_color() {
    return color_;
}

void MainWindow::set_color(QColor color) {
    color_ = color;
}

void MainWindow::check_rgb(int number, QColor color) {
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(red));
        ui->lineEdit_2->setText(QString::number(green));
        ui->lineEdit_3->setText(QString::number(blue));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(red));
        ui->lineEdit_6->setText(QString::number(green));
        ui->lineEdit_7->setText(QString::number(blue));
    }
    else {
        ui->lineEdit_9->setText(QString::number(red));
        ui->lineEdit_10->setText(QString::number(green));
        ui->lineEdit_11->setText(QString::number(blue));
    }
}

void MainWindow::check_cmyk(int number, QColor color) {
    int cyan = color.cyan();
    int magenta = color.magenta();
    int yellow = color.yellow();
    int black = color.black();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(cyan));
        ui->lineEdit_2->setText(QString::number(magenta));
        ui->lineEdit_3->setText(QString::number(yellow));
        ui->lineEdit_4->setText(QString::number(black));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(cyan));
        ui->lineEdit_6->setText(QString::number(magenta));
        ui->lineEdit_7->setText(QString::number(yellow));
        ui->lineEdit_8->setText(QString::number(black));
    }
    else {
        ui->lineEdit_9->setText(QString::number(cyan));
        ui->lineEdit_10->setText(QString::number(magenta));
        ui->lineEdit_11->setText(QString::number(yellow));
        ui->lineEdit_12->setText(QString::number(black));
    }
}

void MainWindow::check_hls(int number, QColor color) {
    color.toHsl();
    color.hue();
    color.lightness();
    color.saturation();
    int hue = color.hue();
    int saturation = color.saturation();
    int ligth = color.lightness();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(hue));
        ui->lineEdit_2->setText(QString::number(saturation));
        ui->lineEdit_3->setText(QString::number(ligth));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(hue));
        ui->lineEdit_6->setText(QString::number(saturation));
        ui->lineEdit_7->setText(QString::number(ligth));
    }
    else {
        ui->lineEdit_9->setText(QString::number(hue));
        ui->lineEdit_10->setText(QString::number(saturation));
        ui->lineEdit_11->setText(QString::number(ligth));
        ligth += 1;
        saturation += 1;
        hue += 1;
    }
}

void MainWindow::check_lab(int number, QColor color) {
    int green = color.green();
    int red = color.red();
    int blue = color.blue();
    Con.RGBtoXYZ(red, green, blue);
    Con.XYZtoLAB(Con.getX(), Con.getY(), Con.getZ());
    int l = Con.getCIA_L();
    int a = Con.getCIA_A();
    int b = Con.getCIA_B();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(l));
        ui->lineEdit_2->setText(QString::number(a));
        ui->lineEdit_3->setText(QString::number(b));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(l));
        ui->lineEdit_6->setText(QString::number(a));
        ui->lineEdit_7->setText(QString::number(b));
    }
    else {
        ui->lineEdit_9->setText(QString::number(l));
        ui->lineEdit_10->setText(QString::number(a));
        ui->lineEdit_11->setText(QString::number(b));
    }
}

void MainWindow::check_xyz(int number, QColor color) {
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    Con.RGBtoXYZ(red, green, blue);
    int x = Con.getX();
    int y = Con.getY();
    int z = Con.getZ();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(x));
        ui->lineEdit_2->setText(QString::number(y));
        ui->lineEdit_3->setText(QString::number(z));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(x));
        ui->lineEdit_6->setText(QString::number(y));
        ui->lineEdit_7->setText(QString::number(z));
    }
    else {
        ui->lineEdit_9->setText(QString::number(x));
        ui->lineEdit_10->setText(QString::number(y));
        ui->lineEdit_11->setText(QString::number(z));
    }
}

void MainWindow::check_hsv(int number, QColor color) {
    int hue = color.hue();
    int saturarion = color.saturation();
    int value = color.value();
    if(number == 1) {
        ui->lineEdit->setText(QString::number(hue));
        ui->lineEdit_2->setText(QString::number(saturarion));
        ui->lineEdit_3->setText(QString::number(value));
    }
    else if (number == 2) {
        ui->lineEdit_5->setText(QString::number(hue));
        ui->lineEdit_6->setText(QString::number(saturarion));
        ui->lineEdit_7->setText(QString::number(value));
    }
    else {
        ui->lineEdit_9->setText(QString::number(hue));
        ui->lineEdit_10->setText(QString::number(saturarion));
        ui->lineEdit_11->setText(QString::number(value));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(index_2 == 0) {
        convert_rgb();
    } else if(index_2 == 1) {
        convert_hsv();
    } else if(index_2 == 2) {
        convert_hls();
    } else if(index_2 == 3) {
        convert_lab();
    } else if(index_2 == 4) {
        convert_cmyk();
    } else if(index_2 == 5) {
        convert_xyz();
    }
}

void MainWindow::convert_rgb() {
    QColor new_color;
    int red, green, blue;
        red = ui->lineEdit_13->text().toInt();
        green = ui->lineEdit_14->text().toInt();
        blue = ui->lineEdit_15->text().toInt();

    new_color.setRgb(red, green, blue);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);
}



void MainWindow::convert_cmyk() {
    QColor new_color;
    int cyan, magenta, yellow, black;
        cyan = ui->lineEdit_13->text().toInt();
        magenta = ui->lineEdit_14->text().toInt();
        yellow = ui->lineEdit_15->text().toInt();
        black = ui->lineEdit_16->text().toInt();
    new_color.setCmyk(cyan, magenta, yellow, black);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);
}

void MainWindow::convert_hls() {
    QColor new_color;
    int hue, light, saturation;

        hue = ui->lineEdit_13->text().toInt();
        light = ui->lineEdit_14->text().toInt();
        saturation = ui->lineEdit_15->text().toInt();

    new_color.setHsl(hue, saturation, light);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);
}

void MainWindow::convert_hsv() {
    QColor new_color;
    int hue, value, saturation;

        hue = ui->lineEdit_13->text().toInt();
        saturation = ui->lineEdit_14->text().toInt();
        value = ui->lineEdit_15->text().toInt();

    new_color.setHsv(hue, saturation, value);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);

}

void MainWindow::convert_xyz() {
    QColor new_color;
    int x, y, z;

        x = ui->lineEdit_13->text().toInt();
        y = ui->lineEdit_14->text().toInt();
        z = ui->lineEdit_15->text().toInt();

    Con.XYZtoRGB(x, y, z);
    int new_red = Con.getRed();
    int new_green = Con.getGreen();
    int new_blue = Con.getBlue();



        new_color.setRgb(new_red, new_green, new_blue);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);
}

void MainWindow::convert_lab() {
    QColor new_color;
    int l, a, b;
        l = ui->lineEdit_13->text().toInt();
        a = ui->lineEdit_14->text().toInt();
        b = ui->lineEdit_15->text().toInt();
    Con.LABtoRGB(l, a, b);

        int new_red = Con.getRed();
        int new_green = Con.getGreen();
        int new_blue = Con.getBlue();
        new_color.setRgb(new_red, new_green, new_blue);
        write_colors(get_index(), new_color);
        draw_current_color(new_color);
        set_color(new_color);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    int cyan = get_color().cyan();
    int magenta = get_color().magenta();
    int yellow = get_color().yellow();
    int black = value;
    QColor new_color;
    new_color.setCmyk(cyan, magenta, yellow, black);
    write_colors(get_index(), new_color);
    draw_current_color(new_color);
    set_color(new_color);
}
