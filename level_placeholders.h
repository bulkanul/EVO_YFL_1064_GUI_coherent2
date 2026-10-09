#ifndef LEVEL_PLACEHOLDERS_H
#define LEVEL_PLACEHOLDERS_H

#include <QFont>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <cmath>

namespace level_placeholders {

inline QLabel *add(QGridLayout *grid, QWidget *parent, int row, int column,
                   const char *objectName)
{
    auto *value = new QLabel(QString::fromUtf8("—"), parent);
    value->setObjectName(QString::fromLatin1(objectName));
    value->setAlignment(Qt::AlignCenter);
    value->setFont(QFont("Arial", 9));
    value->setToolTip("Threshold unavailable");
    grid->addWidget(value, row, column);
    return value;
}

inline void addSeparator(QGridLayout *grid, QWidget *parent, int row,
                         int column, int columnSpan)
{
    auto *line = new QFrame(parent);
    line->setFrameShape(QFrame::NoFrame);
    line->setFixedHeight(1);
    line->setStyleSheet("background-color: #666666;");
    grid->addWidget(line, row, column, 1, columnSpan);
}

inline void addHeading(QGridLayout *grid, QWidget *parent, int row, int columns)
{
    auto *title = new QLabel("Levels", parent);
    title->setFont(QFont("Arial", 9));
    grid->addWidget(title, row, 0);
    addSeparator(grid, parent, row, 1, columns - 1);
}

enum class LimitKind { Maximum, Minimum };

inline void colorReading(QLabel *reading, double value, double limit, LimitKind kind)
{
    if (!std::isfinite(value) || !std::isfinite(limit)) {
        reading->setStyleSheet({});
        return;
    }

    const bool exceeded = kind == LimitKind::Maximum ? value > limit : value < limit;
    const bool near = limit > 0 &&
            (kind == LimitKind::Maximum ? value >= limit * 0.85 : value <= limit * 1.15);
    reading->setStyleSheet(exceeded ? "color: #c62828; font-weight: bold;"
                                    : near ? "color: #a65f00; font-weight: bold;" : "");
}

} // namespace level_placeholders

#endif // LEVEL_PLACEHOLDERS_H
