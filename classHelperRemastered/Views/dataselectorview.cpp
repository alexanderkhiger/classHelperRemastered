#include "dataselectorview.h"

DataSelectorView::DataSelectorView(QueryService *service,
                                   QString tableName,
                                   receivedFacultyName = 0,
                                   QString receivedSpecialtyName = 0,
                                   QString receivedDisciplineName = 0,
                                   QString uID = 0,
                                   int alwaysInsert = 0) {
    this->service = service;
    faculty_id = 0;
    specialty_id = 0;
    discipline_id = 0;
    receivedID = uID;
    facultyName = receivedFacultyName;
    specialtyName = receivedSpecialtyName;
    disciplineName = receivedDisciplineName;
    facultyModel = new QSqlTableModel;
    specialtyModel = new QSqlTableModel;
    disciplineModel = new QSqlTableModel;
    createUI();

    if (facultyName != "noValue") {
        topLabel->setText(tr("Факультет с названием %1 не найден. Выберите подходящий факультет или создайте новую запись").arg(receivedFacultyName));
        createButton->setText(tr("Создать факультет с названием %1").arg(receivedFacultyName));
        connect(runner,SIGNAL(returnTableModel(QSqlTableModel*)),this,SLOT(setFacultyModel(QSqlTableModel*)));
        runner->tryTableModel(tableName);
    }
    else if (specialtyName != "noValue") {
        topLabel->setText(tr("Специальность с названием %1 не найдена. Выберите подходящую специальность или создайте новую запись").arg(receivedSpecialtyName));
        createButton->setText(tr("Создать специальность с названием %1").arg(receivedSpecialtyName));
        connect(runner,SIGNAL(returnTableModel(QSqlTableModel*)),this,SLOT(setSpecialtyModel(QSqlTableModel*)));
        runner->tryTableModel(tableName);
    }
    else if (disciplineName != "noValue") {
        topLabel->setText(tr("Дисциплина с названием %1 не найдена. Выберите подходящую дисциплину или создайте новую запись").arg(disciplineName));
        createButton->setText(tr("Создать дисциплину с названием %1").arg(disciplineName));
        connect(runner,SIGNAL(returnTableModel(QSqlTableModel*)),this,SLOT(setDisciplineModel(QSqlTableModel*)));
        runner->tryTableModel(tableName);
    }


    if (alwaysInsert == 1)
    {
        createButtonClicked();
    }

}
