#include <QApplication>
#include <QWidget>
#include <QPainter>

class ParabolaPlot : public QWidget {
public:
    ParabolaPlot(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);

        int width = this->width();
        int height = this->height();

        painter.setRenderHint(QPainter::Antialiasing);
        painter.fillRect(0, 0, width, height, Qt::white);

        // Plot the parabola
        painter.setPen(Qt::blue);
        for (int x = 0; x < width; x++) {
            int y = a * x * x + b * x + c;
            painter.drawPoint(x, height - y);
        }
    }

private:
    int a = 1; // You can adjust these coefficients to change the parabola's shape
    int b = 0;
    int c = 0;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ParabolaPlot parabolaPlot;
    parabolaPlot.setWindowTitle("Parabola Plot");
    parabolaPlot.resize(400, 300);
    parabolaPlot.show();

    return app.exec();
}
