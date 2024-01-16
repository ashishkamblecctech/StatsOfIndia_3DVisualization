#include "stdafx.h"
#include "StatsOfIndia.h"

StatsOfIndia::StatsOfIndia(QWidget *parent) 
    : QMainWindow(parent)
{
    setupUi();

    //Connection to handle combo box UI
    connect(mComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &StatsOfIndia::handleComboBoxChange);
}

StatsOfIndia::~StatsOfIndia()
{}

void StatsOfIndia::setupUi()
{
    // Set a minimum and maximum size for the main window
    this->setMinimumSize(800, 600);
    this->setMaximumSize(1900, 1000);

    // UI part can be added in the code below
    resize(1900, 1000);
    this->setWindowTitle("Stats of India - 3D Visualization");

    mCentralWidget = new QWidget(this);

    mGridLayoutWidget = new QWidget(mCentralWidget);
    mGridLayoutWidget->setGeometry(QRect(0, 0, 1900, 1000));
    mGridLayout = new QGridLayout(mGridLayoutWidget);

    mVerticalLayout = new QVBoxLayout();
    mHorizontalLayout = new QHBoxLayout();

    mComboBox = new QComboBox(mGridLayoutWidget);

    mComboBox->addItem("Select any parameters:");

    QIcon populationIcon("Icons/population_icon.png");
    mComboBox->addItem(populationIcon, "Population");

    QIcon educationIcon("Icons/education_icon.png");
    mComboBox->addItem(educationIcon, "Education");

    QIcon areaIcon("Icons/area_icon.png");
    mComboBox->addItem(areaIcon, "Area");

    mComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents); // To make page responsive

    mComboBox->setStyleSheet("QComboBox { background-color: white; border: 2px solid darkblue; padding: 5px; }");

    mVerticalLayout->addWidget(mComboBox);

    mTableView = new QTableView(mGridLayoutWidget);
    mTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // To make page responsive
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    mTableView->setSizePolicy(sizePolicy);
    mTableView->setStyleSheet("QTableView { background-color: white; }"
        "QHeaderView::section { background-color: lightblue; border: 1px solid darkblue; }"
        "QTableView::item { border: 1px solid darkblue; }");
    mVerticalLayout->addWidget(mTableView);

    mGridLayout->addLayout(mVerticalLayout, 0, 1, 1, 1);
    mCentralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mCentralWidget->setLayout(mGridLayout);
    setCentralWidget(mCentralWidget);
    mOpenGLWidget = new OpenGLWindow(QColor(0, 0, 0), mCentralWidget);
    mGridLayout->addWidget(mOpenGLWidget, 0, 0, 2, 1); // Spanning two rows
}

void StatsOfIndia::setupTableModel(const QStringList& stateNames, const QList<long>& stateValues)
{
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList() << "State Names" << "Values");

    for (int i = 0; i < stateNames.size(); i++) {
        QList<QStandardItem*> row;
        row << new QStandardItem(stateNames[i]); // Add state name to the first column
        row << new QStandardItem(QString::number(stateValues[i])); // Add the corresponding value for the second column
        model->appendRow(row);
    }

    mTableView->setModel(model); // Set the model for the table view
}

void StatsOfIndia::handleComboBoxChange(int index) {

    stateNames.resize(31); // Fix the size of array to 31

    StatsDataReader reader;
    reader.dataReader(stateNames, regions1); //Calling the reader and gathering all the data from the reader

    mOpenGLWidget->clearRegions();

    switch (index) {
    case 1: // Handle Population selection
    {  
        // Pass the data to setupTableModel
        QStringList stateNames1;
        QList<long> stateValues1;
        for (int i = 0; i < stateNames.size(); i++) {
            stateNames1 << QString::fromStdString(stateNames[i]);
            stateValues1 << regions1[i].statePopulation;
        }
        setupTableModel(stateNames1, stateValues1);

        // Loop through the array and call addFilePoints for each region
        for (RegionInfo1& region : regions1) {
            mOpenGLWidget->addFilePoints(region.filePath, region.r, region.g, region.b, (region.statePopulation / 10000000));
        }
        update();
        break;
    }
    case 2: // Handle Education selection
    { 
        // Pass the data to setupTableModel
        QStringList stateNames2;
        QList<long> stateValues2;
        for (int i = 0; i < stateNames.size(); i++) {
            stateNames2 << QString::fromStdString(stateNames[i]);
            stateValues2 << regions1[i].stateEducation ;
        }
        setupTableModel(stateNames2, stateValues2);

        // Loop through the array and call addFilePoints for each region
        for (RegionInfo1& region : regions1) {
            mOpenGLWidget->addFilePoints(region.filePath, region.r, region.g, region.b, (region.stateEducation - 60) / 2);
        }
        update();
        break;
    }
        
    case 3: // Handle Area selection
    {
        // Pass the data to setupTableModel
        QStringList stateNames3;
        QList<long> stateValues3;
        for (int i = 0; i < stateNames.size(); i++) {
            stateNames3 << QString::fromStdString(stateNames[i]);
            stateValues3 << regions1[i].stateArea ;
        }
        setupTableModel(stateNames3, stateValues3);

        // Loop through the array and call addFilePoints for each region
        for (RegionInfo1& region : regions1) {
            mOpenGLWidget->addFilePoints(region.filePath, region.r, region.g, region.b, (region.stateArea / 20000));
        }
        update();
        break;
    }
        
        // We can add more cases as needed
    }
}