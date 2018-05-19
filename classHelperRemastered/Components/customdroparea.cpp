#include "customdroparea.h"

CustomDropArea::CustomDropArea() {
    createUI();
}

void CustomDropArea::createUI() {
    setMinimumSize(300, 100);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAlignment(Qt::AlignCenter);
    setAcceptDrops(true);
    setWordWrap(true);
    setAutoFillBackground(true);
    clear();
}

void CustomDropArea::dragEnterEvent(QDragEnterEvent *event) {
    setText(tr("Перетащите сюда элемент из списка или сделайте двойной клик на элементе списка"));
    setBackgroundRole(QPalette::Highlight);
    event->acceptProposedAction();
}

void CustomDropArea::dragMoveEvent(QDragMoveEvent *event) {
    event->acceptProposedAction();
}

void CustomDropArea::dropEvent(QDropEvent *event) {
    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();
    emit itemDropped(event->source(), event->mimeData());
}

void CustomDropArea::dragLeaveEvent(QDragLeaveEvent *event) {
    setBackgroundRole(QPalette::Dark);
    event->accept();
}

void CustomDropArea::clear() {
    setText(tr("Перетащите сюда элемент из списка или сделайте двойной клик на элементе списка"));
    setBackgroundRole(QPalette::Dark);
    emit areaCleared();
}
