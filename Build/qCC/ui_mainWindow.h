/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ccConsole.h>
#include <ccDBRoot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionFullScreen;
    QAction *actionDisplayOptions;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionSetUniqueColor;
    QAction *actionSetColorGradient;
    QAction *actionComputeNormals;
    QAction *actionInvertNormals;
    QAction *actionComputeOctree;
    QAction *actionConsole;
    QAction *actionClose3DView;
    QAction *actionCloseAll3DViews;
    QAction *actionTile3DViews;
    QAction *actionCascade3DViews;
    QAction *actionPrevious3DView;
    QAction *actionNext3DView;
    QAction *actionNew3DView;
    QAction *actionClone;
    QAction *actionMerge;
    QAction *actionDelete;
    QAction *actionRegister;
    QAction *actionCloudCloudDist;
    QAction *actionCloudMeshDist;
    QAction *actionStatisticalTest;
    QAction *actionSamplePointsOnMesh;
    QAction *actionLabelConnectedComponents;
    QAction *actionSegment;
    QAction *actionTranslateRotate;
    QAction *actionShowHistogram;
    QAction *actionComputeStatParams;
    QAction *actionFilterByValue;
    QAction *actionGaussianFilter;
    QAction *actionDeleteScalarField;
    QAction *actionScalarFieldArithmetic;
    QAction *actionColorize;
    QAction *actionSmoothMeshSF;
    QAction *actionEnhanceMeshSF;
    QAction *actionClearColor;
    QAction *actionClearNormals;
    QAction *actionResampleWithOctree;
    QAction *actionComputeMeshAA;
    QAction *actionComputeMeshLS;
    QAction *actionMeasureMeshSurface;
    QAction *actionCPS;
    QAction *actionDeleteAllSF;
    QAction *actionMultiplySF;
    QAction *actionKMeans;
    QAction *actionFrontPropagation;
    QAction *actionApplyScale;
    QAction *actionMatchBBCenters;
    QAction *actionUnroll;
    QAction *actionSFGradient;
    QAction *actionZoomAndCenter;
    QAction *actionSetViewTop;
    QAction *actionSetViewFront;
    QAction *actionSetViewBack;
    QAction *actionSetViewLeft;
    QAction *actionSetViewRight;
    QAction *actionSetViewBottom;
    QAction *actionDisplayMainTools;
    QAction *actionDisplayViewTools;
    QAction *actionDisplayScalarFieldsTools;
    QAction *actionToggleSunLight;
    QAction *actionToggleCustomLight;
    QAction *actionGlobalZoom;
    QAction *actionToggleCenteredPerspective;
    QAction *actionToggleViewerBasedPerspective;
    QAction *actionRefresh;
    QAction *actionTestFrameRate;
    QAction *actionRenderToFile;
    QAction *actionAboutPlugins;
    QAction *actionConvertToRGB;
    QAction *actionShowDepthBuffer;
    QAction *actionExportDepthBuffer;
    QAction *actionModifySensor;
    QAction *actionRasterize;
    QAction *actionAlign;
    QAction *actionSubsample;
    QAction *actionLoadShader;
    QAction *actionDeleteShader;
    QAction *actionPointPicking;
    QAction *actionComputeBestFitBB;
    QAction *actionEditCamera;
    QAction *actionPointListPicking;
    QAction *actionCurvature;
    QAction *actionRoughness;
    QAction *actionFitPlane;
    QAction *actionRenameSF;
    QAction *actionFitQuadric;
    QAction *actionSNETest;
    QAction *actionToggleVisibility;
    QAction *actionToggleNormals;
    QAction *actionToggleColors;
    QAction *actionToggleSF;
    QAction *actionApplyTransformation;
    QAction *actionSmoothMeshLaplacian;
    QAction *actionConvertNormalToHSV;
    QAction *actionSaveViewportAsObject;
    QAction *actionPickRotationCenter;
    QAction *actionComputeDistancesFromSensor;
    QAction *actionBilateralFilter;
    QAction *actionComputeScatteringAngles;
    QAction *actionToggleActiveSFColorScale;
    QAction *actionShowActiveSFPrevious;
    QAction *actionShowActiveSFNext;
    QAction *actionPointPairsAlign;
    QAction *actionAddConstantSF;
    QAction *actionExportCoordToSF;
    QAction *actionSubdivideMesh;
    QAction *actionToggleShowName;
    QAction *actionPrimitiveFactory;
    QAction *actionToggleMaterials;
    QAction *actionSetOrthoView;
    QAction *actionSetCenteredPerspectiveView;
    QAction *actionSetViewerPerspectiveView;
    QAction *actionSetPivotAlwaysOn;
    QAction *actionSetPivotRotationOnly;
    QAction *actionSetPivotOff;
    QAction *actionSetViewIso1;
    QAction *actionSetViewIso2;
    QAction *actionConvertTextureToColor;
    QAction *actionOpenColorScalesManager;
    QAction *actionCrossSection;
    QAction *actionEditGlobalShiftAndScale;
    QAction *actionScalarFieldFromColor;
    QAction *actionComputeKdTree;
    QAction *actionTest;
    QAction *actionAddIdField;
    QAction *actionFitFacet;
    QAction *actionAdjustZoom;
    QAction *actionSetSFAsCoord;
    QAction *actionCloseAll;
    QAction *actionEditGlobalScale;
    QAction *actionViewFromSensor;
    QAction *actionFindBiggestInnerRectangle;
    QAction *actionCreateGBLSensor;
    QAction *actionCreateCameraSensor;
    QAction *actionCheckPointsInsideFrustum;
    QAction *actionProjectUncertainty;
    QAction *actionOrientNormalsMST;
    QAction *actionOrientNormalsFM;
    QAction *actionCNETest;
    QAction *actionApproximateDensity;
    QAction *actionComputeDensity;
    QAction *actionRemoveDuplicatePoints;
    QAction *actionCrop;
    QAction *actionConvertNormalToDipDir;
    QAction *actionExportCloudInfo;
    QAction *actionInterpolateColors;
    QAction *actionDistanceToBestFitQuadric3D;
    QAction *actionChangeColorLevels;
    QAction *actionResetGUIElementsPos;
    QAction *actionConvertToRandomRGB;
    QAction *actionNoiseFilter;
    QAction *actionComputeStatParams2;
    QAction *actionMeasureMeshVolume;
    QAction *actionFlagMeshVertices;
    QAction *actionToggleActivation;
    QAction *actionLockRotationAxis;
    QAction *actionCreateCloudFromEntCenters;
    QAction *actionComputeBestICPRmsMatrix;
    QAction *actionEnterBubbleViewMode;
    QAction *actionExtractSections;
    QAction *actionConvertPolylinesToMesh;
    QAction *actionLevel;
    QAction *actionFitSphere;
    QAction *actionMatchScales;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionDistanceMap;
    QAction *actionSORFilter;
    QAction *actionEnableStereo;
    QAction *actionComputePointsVisibility;
    QAction *actionCompute2HalfDimVolume;
    QAction *actionExclusiveFullScreen;
    QAction *actionEnableVisualDebugTraces;
    QAction *actionRGBToGreyScale;
    QAction *actionTracePolyline;
    QAction *actionEnableQtWarnings;
    QAction *actionGlobalShiftSettings;
    QAction *actionEnableCameraLink;
    QAction *actionShowWaveDialog;
    QAction *actionCreatePlane;
    QAction *actionEditPlane;
    QAction *actionCreateSurfaceBetweenTwoPolylines;
    QAction *actionMeshTwoPolylines;
    QAction *actionFitPlaneProxy;
    QAction *actionEnhanceRGBWithIntensities;
    QAction *actionMeshScanGrids;
    QAction *actionAutoPickRotationCenter;
    QAction *actionShowCursor3DCoordinates;
    QAction *actionDeleteScanGrid;
    QAction *actionCompressFWFData;
    QAction *actionInterpolateSFs;
    QAction *actionExportPlaneInfo;
    QAction *actionLock_rotation_about_arbitrary_axis;
    QAction *actionSamplePointsOnPolyline;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDisplay;
    QMenu *menuToolbars;
    QMenu *menuLights;
    QMenu *menuActiveScalarField;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuScalarFields;
    QMenu *menuColors;
    QMenu *menuNormals;
    QMenu *menuOrientNormals;
    QMenu *menuConvert_to;
    QMenu *menuOctree;
    QMenu *menuMesh;
    QMenu *menuMeshScalarField;
    QMenu *menuSensors;
    QMenu *menuGroundBasedLidar;
    QMenu *menuCameraSensor;
    QMenu *menuToggle;
    QMenu *menuWaveform;
    QMenu *menuPlane;
    QMenu *menuGrid;
    QMenu *menuPolyline;
    QMenu *menu3DViews;
    QMenu *menuTools;
    QMenu *menuSegmentation;
    QMenu *menuProjection;
    QMenu *menuStatistics;
    QMenu *menuDistances;
    QMenu *menuRegistration;
    QMenu *menuOther;
    QMenu *menuSandBox;
    QMenu *menuFit;
    QMenu *menuClean;
    QMenu *menuVolume;
    QMenu *menuBatchExport;
    QDockWidget *DockableDBTree;
    QWidget *dockWidgetContents;
    QVBoxLayout *vboxLayout;
    ccCustomQTreeView *dbTreeView;
    QStatusBar *statusBar;
    QToolBar *toolBarView;
    QDockWidget *DockableConsole;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *vboxLayout1;
    ccCustomQListWidget *consoleWidget;
    QToolBar *toolBarMainTools;
    QToolBar *toolBarSFTools;
    QDockWidget *DockableProperties;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *vboxLayout2;
    QTreeView *propertiesTreeView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/Icons/images/icon/cc_icon_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/ccOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/ccSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave->setShortcutContext(Qt::ApplicationShortcut);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionFullScreen = new QAction(MainWindow);
        actionFullScreen->setObjectName(QStringLiteral("actionFullScreen"));
        actionFullScreen->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CC/images/ccFullScreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFullScreen->setIcon(icon3);
        actionFullScreen->setShortcutContext(Qt::ApplicationShortcut);
        actionDisplayOptions = new QAction(MainWindow);
        actionDisplayOptions->setObjectName(QStringLiteral("actionDisplayOptions"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CC/images/monitor.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisplayOptions->setIcon(icon4);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSetUniqueColor = new QAction(MainWindow);
        actionSetUniqueColor->setObjectName(QStringLiteral("actionSetUniqueColor"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CC/images/typeRgbCcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetUniqueColor->setIcon(icon5);
        actionSetColorGradient = new QAction(MainWindow);
        actionSetColorGradient->setObjectName(QStringLiteral("actionSetColorGradient"));
        actionComputeNormals = new QAction(MainWindow);
        actionComputeNormals->setObjectName(QStringLiteral("actionComputeNormals"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CC/images/typeNormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComputeNormals->setIcon(icon6);
        actionInvertNormals = new QAction(MainWindow);
        actionInvertNormals->setObjectName(QStringLiteral("actionInvertNormals"));
        actionComputeOctree = new QAction(MainWindow);
        actionComputeOctree->setObjectName(QStringLiteral("actionComputeOctree"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/CC/images/dbOctreeSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComputeOctree->setIcon(icon7);
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QStringLiteral("actionConsole"));
        actionConsole->setCheckable(true);
        actionConsole->setChecked(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/CC/images/ccConsole.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConsole->setIcon(icon8);
        actionConsole->setShortcutContext(Qt::ApplicationShortcut);
        actionClose3DView = new QAction(MainWindow);
        actionClose3DView->setObjectName(QStringLiteral("actionClose3DView"));
        actionCloseAll3DViews = new QAction(MainWindow);
        actionCloseAll3DViews->setObjectName(QStringLiteral("actionCloseAll3DViews"));
        actionTile3DViews = new QAction(MainWindow);
        actionTile3DViews->setObjectName(QStringLiteral("actionTile3DViews"));
        actionCascade3DViews = new QAction(MainWindow);
        actionCascade3DViews->setObjectName(QStringLiteral("actionCascade3DViews"));
        actionPrevious3DView = new QAction(MainWindow);
        actionPrevious3DView->setObjectName(QStringLiteral("actionPrevious3DView"));
        actionNext3DView = new QAction(MainWindow);
        actionNext3DView->setObjectName(QStringLiteral("actionNext3DView"));
        actionNew3DView = new QAction(MainWindow);
        actionNew3DView->setObjectName(QStringLiteral("actionNew3DView"));
        actionClone = new QAction(MainWindow);
        actionClone->setObjectName(QStringLiteral("actionClone"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/CC/images/ccClone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClone->setIcon(icon9);
        actionMerge = new QAction(MainWindow);
        actionMerge->setObjectName(QStringLiteral("actionMerge"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/CC/images/ccMerge.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMerge->setIcon(icon10);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/CC/images/ccDelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon11);
        actionDelete->setShortcutContext(Qt::ApplicationShortcut);
        actionRegister = new QAction(MainWindow);
        actionRegister->setObjectName(QStringLiteral("actionRegister"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/CC/images/ccRegister.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRegister->setIcon(icon12);
        actionCloudCloudDist = new QAction(MainWindow);
        actionCloudCloudDist->setObjectName(QStringLiteral("actionCloudCloudDist"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/CC/images/ccCloudCloudDistance.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloudCloudDist->setIcon(icon13);
        actionCloudMeshDist = new QAction(MainWindow);
        actionCloudMeshDist->setObjectName(QStringLiteral("actionCloudMeshDist"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/CC/images/ccCloudMeshDistance.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloudMeshDist->setIcon(icon14);
        actionStatisticalTest = new QAction(MainWindow);
        actionStatisticalTest->setObjectName(QStringLiteral("actionStatisticalTest"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/CC/images/ccStatTest.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStatisticalTest->setIcon(icon15);
        actionSamplePointsOnMesh = new QAction(MainWindow);
        actionSamplePointsOnMesh->setObjectName(QStringLiteral("actionSamplePointsOnMesh"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/CC/images/ccSamplePoints.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSamplePointsOnMesh->setIcon(icon16);
        actionLabelConnectedComponents = new QAction(MainWindow);
        actionLabelConnectedComponents->setObjectName(QStringLiteral("actionLabelConnectedComponents"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/CC/images/ccCCExtract.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLabelConnectedComponents->setIcon(icon17);
        actionSegment = new QAction(MainWindow);
        actionSegment->setObjectName(QStringLiteral("actionSegment"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/CC/images/ccSegment.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSegment->setIcon(icon18);
        actionTranslateRotate = new QAction(MainWindow);
        actionTranslateRotate->setObjectName(QStringLiteral("actionTranslateRotate"));
        actionTranslateRotate->setCheckable(false);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/CC/images/ccInteractiveTransformation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTranslateRotate->setIcon(icon19);
        actionShowHistogram = new QAction(MainWindow);
        actionShowHistogram->setObjectName(QStringLiteral("actionShowHistogram"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/CC/images/ccHistogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowHistogram->setIcon(icon20);
        actionComputeStatParams = new QAction(MainWindow);
        actionComputeStatParams->setObjectName(QStringLiteral("actionComputeStatParams"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/CC/images/ccComputeStat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComputeStatParams->setIcon(icon21);
        actionFilterByValue = new QAction(MainWindow);
        actionFilterByValue->setObjectName(QStringLiteral("actionFilterByValue"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/CC/images/ccFilterByValue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFilterByValue->setIcon(icon22);
        actionGaussianFilter = new QAction(MainWindow);
        actionGaussianFilter->setObjectName(QStringLiteral("actionGaussianFilter"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/CC/images/ccGaussianFilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGaussianFilter->setIcon(icon23);
        actionDeleteScalarField = new QAction(MainWindow);
        actionDeleteScalarField->setObjectName(QStringLiteral("actionDeleteScalarField"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/CC/images/ccDeleteSF.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteScalarField->setIcon(icon24);
        actionScalarFieldArithmetic = new QAction(MainWindow);
        actionScalarFieldArithmetic->setObjectName(QStringLiteral("actionScalarFieldArithmetic"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/CC/images/ccSfArithmetic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScalarFieldArithmetic->setIcon(icon25);
        actionColorize = new QAction(MainWindow);
        actionColorize->setObjectName(QStringLiteral("actionColorize"));
        actionSmoothMeshSF = new QAction(MainWindow);
        actionSmoothMeshSF->setObjectName(QStringLiteral("actionSmoothMeshSF"));
        actionEnhanceMeshSF = new QAction(MainWindow);
        actionEnhanceMeshSF->setObjectName(QStringLiteral("actionEnhanceMeshSF"));
        actionClearColor = new QAction(MainWindow);
        actionClearColor->setObjectName(QStringLiteral("actionClearColor"));
        actionClearColor->setIcon(icon11);
        actionClearNormals = new QAction(MainWindow);
        actionClearNormals->setObjectName(QStringLiteral("actionClearNormals"));
        actionClearNormals->setIcon(icon11);
        actionResampleWithOctree = new QAction(MainWindow);
        actionResampleWithOctree->setObjectName(QStringLiteral("actionResampleWithOctree"));
        actionComputeMeshAA = new QAction(MainWindow);
        actionComputeMeshAA->setObjectName(QStringLiteral("actionComputeMeshAA"));
        actionComputeMeshLS = new QAction(MainWindow);
        actionComputeMeshLS->setObjectName(QStringLiteral("actionComputeMeshLS"));
        actionMeasureMeshSurface = new QAction(MainWindow);
        actionMeasureMeshSurface->setObjectName(QStringLiteral("actionMeasureMeshSurface"));
        actionCPS = new QAction(MainWindow);
        actionCPS->setObjectName(QStringLiteral("actionCPS"));
        actionDeleteAllSF = new QAction(MainWindow);
        actionDeleteAllSF->setObjectName(QStringLiteral("actionDeleteAllSF"));
        actionMultiplySF = new QAction(MainWindow);
        actionMultiplySF->setObjectName(QStringLiteral("actionMultiplySF"));
        actionKMeans = new QAction(MainWindow);
        actionKMeans->setObjectName(QStringLiteral("actionKMeans"));
        actionKMeans->setCheckable(true);
        actionFrontPropagation = new QAction(MainWindow);
        actionFrontPropagation->setObjectName(QStringLiteral("actionFrontPropagation"));
        actionFrontPropagation->setEnabled(false);
        actionApplyScale = new QAction(MainWindow);
        actionApplyScale->setObjectName(QStringLiteral("actionApplyScale"));
        actionMatchBBCenters = new QAction(MainWindow);
        actionMatchBBCenters->setObjectName(QStringLiteral("actionMatchBBCenters"));
        actionUnroll = new QAction(MainWindow);
        actionUnroll->setObjectName(QStringLiteral("actionUnroll"));
        actionSFGradient = new QAction(MainWindow);
        actionSFGradient->setObjectName(QStringLiteral("actionSFGradient"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/CC/images/ccGradient.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSFGradient->setIcon(icon26);
        actionZoomAndCenter = new QAction(MainWindow);
        actionZoomAndCenter->setObjectName(QStringLiteral("actionZoomAndCenter"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/CC/images/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomAndCenter->setIcon(icon27);
        actionSetViewTop = new QAction(MainWindow);
        actionSetViewTop->setObjectName(QStringLiteral("actionSetViewTop"));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/CC/images/ccViewZpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewTop->setIcon(icon28);
        actionSetViewTop->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewFront = new QAction(MainWindow);
        actionSetViewFront->setObjectName(QStringLiteral("actionSetViewFront"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/CC/images/ccViewYpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewFront->setIcon(icon29);
        actionSetViewFront->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewBack = new QAction(MainWindow);
        actionSetViewBack->setObjectName(QStringLiteral("actionSetViewBack"));
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/CC/images/ccViewYneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewBack->setIcon(icon30);
        actionSetViewBack->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewLeft = new QAction(MainWindow);
        actionSetViewLeft->setObjectName(QStringLiteral("actionSetViewLeft"));
        QIcon icon31;
        icon31.addFile(QStringLiteral(":/CC/images/ccViewXpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewLeft->setIcon(icon31);
        actionSetViewLeft->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewRight = new QAction(MainWindow);
        actionSetViewRight->setObjectName(QStringLiteral("actionSetViewRight"));
        QIcon icon32;
        icon32.addFile(QStringLiteral(":/CC/images/ccViewXneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewRight->setIcon(icon32);
        actionSetViewRight->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewBottom = new QAction(MainWindow);
        actionSetViewBottom->setObjectName(QStringLiteral("actionSetViewBottom"));
        QIcon icon33;
        icon33.addFile(QStringLiteral(":/CC/images/ccViewZneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewBottom->setIcon(icon33);
        actionSetViewBottom->setShortcutContext(Qt::ApplicationShortcut);
        actionDisplayMainTools = new QAction(MainWindow);
        actionDisplayMainTools->setObjectName(QStringLiteral("actionDisplayMainTools"));
        actionDisplayMainTools->setCheckable(true);
        actionDisplayMainTools->setChecked(true);
        actionDisplayViewTools = new QAction(MainWindow);
        actionDisplayViewTools->setObjectName(QStringLiteral("actionDisplayViewTools"));
        actionDisplayViewTools->setCheckable(true);
        actionDisplayViewTools->setChecked(true);
        actionDisplayScalarFieldsTools = new QAction(MainWindow);
        actionDisplayScalarFieldsTools->setObjectName(QStringLiteral("actionDisplayScalarFieldsTools"));
        actionDisplayScalarFieldsTools->setCheckable(true);
        actionDisplayScalarFieldsTools->setChecked(true);
        actionToggleSunLight = new QAction(MainWindow);
        actionToggleSunLight->setObjectName(QStringLiteral("actionToggleSunLight"));
        actionToggleSunLight->setShortcutContext(Qt::ApplicationShortcut);
        actionToggleCustomLight = new QAction(MainWindow);
        actionToggleCustomLight->setObjectName(QStringLiteral("actionToggleCustomLight"));
        actionToggleCustomLight->setShortcutContext(Qt::ApplicationShortcut);
        actionGlobalZoom = new QAction(MainWindow);
        actionGlobalZoom->setObjectName(QStringLiteral("actionGlobalZoom"));
        QIcon icon34;
        icon34.addFile(QStringLiteral(":/CC/images/ccGlobalZoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGlobalZoom->setIcon(icon34);
        actionToggleCenteredPerspective = new QAction(MainWindow);
        actionToggleCenteredPerspective->setObjectName(QStringLiteral("actionToggleCenteredPerspective"));
        QIcon icon35;
        icon35.addFile(QStringLiteral(":/CC/images/ccCenteredPerspective32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToggleCenteredPerspective->setIcon(icon35);
        actionToggleCenteredPerspective->setShortcutContext(Qt::ApplicationShortcut);
        actionToggleViewerBasedPerspective = new QAction(MainWindow);
        actionToggleViewerBasedPerspective->setObjectName(QStringLiteral("actionToggleViewerBasedPerspective"));
        QIcon icon36;
        icon36.addFile(QStringLiteral(":/CC/images/ccViewerBasedPerspective32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToggleViewerBasedPerspective->setIcon(icon36);
        actionToggleViewerBasedPerspective->setShortcutContext(Qt::ApplicationShortcut);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        QIcon icon37;
        icon37.addFile(QStringLiteral(":/CC/images/smallReset.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon37);
        actionRefresh->setShortcutContext(Qt::ApplicationShortcut);
        actionTestFrameRate = new QAction(MainWindow);
        actionTestFrameRate->setObjectName(QStringLiteral("actionTestFrameRate"));
        actionRenderToFile = new QAction(MainWindow);
        actionRenderToFile->setObjectName(QStringLiteral("actionRenderToFile"));
        actionAboutPlugins = new QAction(MainWindow);
        actionAboutPlugins->setObjectName(QStringLiteral("actionAboutPlugins"));
        actionConvertToRGB = new QAction(MainWindow);
        actionConvertToRGB->setObjectName(QStringLiteral("actionConvertToRGB"));
        actionConvertToRGB->setIcon(icon5);
        actionShowDepthBuffer = new QAction(MainWindow);
        actionShowDepthBuffer->setObjectName(QStringLiteral("actionShowDepthBuffer"));
        actionExportDepthBuffer = new QAction(MainWindow);
        actionExportDepthBuffer->setObjectName(QStringLiteral("actionExportDepthBuffer"));
        actionModifySensor = new QAction(MainWindow);
        actionModifySensor->setObjectName(QStringLiteral("actionModifySensor"));
        actionRasterize = new QAction(MainWindow);
        actionRasterize->setObjectName(QStringLiteral("actionRasterize"));
        QIcon icon38;
        icon38.addFile(QStringLiteral(":/CC/images/ccGrid.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRasterize->setIcon(icon38);
        actionAlign = new QAction(MainWindow);
        actionAlign->setObjectName(QStringLiteral("actionAlign"));
        actionSubsample = new QAction(MainWindow);
        actionSubsample->setObjectName(QStringLiteral("actionSubsample"));
        QIcon icon39;
        icon39.addFile(QStringLiteral(":/CC/images/ccSampleCloud.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSubsample->setIcon(icon39);
        actionLoadShader = new QAction(MainWindow);
        actionLoadShader->setObjectName(QStringLiteral("actionLoadShader"));
        actionLoadShader->setEnabled(false);
        actionDeleteShader = new QAction(MainWindow);
        actionDeleteShader->setObjectName(QStringLiteral("actionDeleteShader"));
        actionDeleteShader->setEnabled(false);
        actionPointPicking = new QAction(MainWindow);
        actionPointPicking->setObjectName(QStringLiteral("actionPointPicking"));
        QIcon icon40;
        icon40.addFile(QStringLiteral(":/CC/images/ccPointPicking.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointPicking->setIcon(icon40);
        actionComputeBestFitBB = new QAction(MainWindow);
        actionComputeBestFitBB->setObjectName(QStringLiteral("actionComputeBestFitBB"));
        actionEditCamera = new QAction(MainWindow);
        actionEditCamera->setObjectName(QStringLiteral("actionEditCamera"));
        QIcon icon41;
        icon41.addFile(QStringLiteral(":/CC/images/photo-camera.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditCamera->setIcon(icon41);
        actionPointListPicking = new QAction(MainWindow);
        actionPointListPicking->setObjectName(QStringLiteral("actionPointListPicking"));
        QIcon icon42;
        icon42.addFile(QStringLiteral(":/CC/images/ccPointListPicking.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointListPicking->setIcon(icon42);
        actionCurvature = new QAction(MainWindow);
        actionCurvature->setObjectName(QStringLiteral("actionCurvature"));
        actionRoughness = new QAction(MainWindow);
        actionRoughness->setObjectName(QStringLiteral("actionRoughness"));
        actionRoughness->setEnabled(false);
        actionFitPlane = new QAction(MainWindow);
        actionFitPlane->setObjectName(QStringLiteral("actionFitPlane"));
        actionRenameSF = new QAction(MainWindow);
        actionRenameSF->setObjectName(QStringLiteral("actionRenameSF"));
        actionFitQuadric = new QAction(MainWindow);
        actionFitQuadric->setObjectName(QStringLiteral("actionFitQuadric"));
        actionSNETest = new QAction(MainWindow);
        actionSNETest->setObjectName(QStringLiteral("actionSNETest"));
        actionToggleVisibility = new QAction(MainWindow);
        actionToggleVisibility->setObjectName(QStringLiteral("actionToggleVisibility"));
        actionToggleVisibility->setShortcutContext(Qt::ApplicationShortcut);
        actionToggleNormals = new QAction(MainWindow);
        actionToggleNormals->setObjectName(QStringLiteral("actionToggleNormals"));
        actionToggleNormals->setShortcutContext(Qt::ApplicationShortcut);
        actionToggleColors = new QAction(MainWindow);
        actionToggleColors->setObjectName(QStringLiteral("actionToggleColors"));
        actionToggleColors->setShortcutContext(Qt::ApplicationShortcut);
        actionToggleSF = new QAction(MainWindow);
        actionToggleSF->setObjectName(QStringLiteral("actionToggleSF"));
        actionToggleSF->setShortcutContext(Qt::ApplicationShortcut);
        actionApplyTransformation = new QAction(MainWindow);
        actionApplyTransformation->setObjectName(QStringLiteral("actionApplyTransformation"));
        actionSmoothMeshLaplacian = new QAction(MainWindow);
        actionSmoothMeshLaplacian->setObjectName(QStringLiteral("actionSmoothMeshLaplacian"));
        actionConvertNormalToHSV = new QAction(MainWindow);
        actionConvertNormalToHSV->setObjectName(QStringLiteral("actionConvertNormalToHSV"));
        actionSaveViewportAsObject = new QAction(MainWindow);
        actionSaveViewportAsObject->setObjectName(QStringLiteral("actionSaveViewportAsObject"));
        QIcon icon43;
        icon43.addFile(QStringLiteral(":/CC/images/dbViewportSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveViewportAsObject->setIcon(icon43);
        actionSaveViewportAsObject->setShortcutContext(Qt::ApplicationShortcut);
        actionPickRotationCenter = new QAction(MainWindow);
        actionPickRotationCenter->setObjectName(QStringLiteral("actionPickRotationCenter"));
        QIcon icon44;
        icon44.addFile(QStringLiteral(":/CC/images/ccPickCenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPickRotationCenter->setIcon(icon44);
        actionPickRotationCenter->setShortcutContext(Qt::ApplicationShortcut);
        actionComputeDistancesFromSensor = new QAction(MainWindow);
        actionComputeDistancesFromSensor->setObjectName(QStringLiteral("actionComputeDistancesFromSensor"));
        actionBilateralFilter = new QAction(MainWindow);
        actionBilateralFilter->setObjectName(QStringLiteral("actionBilateralFilter"));
        QIcon icon45;
        icon45.addFile(QStringLiteral(":/CC/images/ccBilateralFilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBilateralFilter->setIcon(icon45);
        actionComputeScatteringAngles = new QAction(MainWindow);
        actionComputeScatteringAngles->setObjectName(QStringLiteral("actionComputeScatteringAngles"));
        actionToggleActiveSFColorScale = new QAction(MainWindow);
        actionToggleActiveSFColorScale->setObjectName(QStringLiteral("actionToggleActiveSFColorScale"));
        actionToggleActiveSFColorScale->setShortcutContext(Qt::ApplicationShortcut);
        actionShowActiveSFPrevious = new QAction(MainWindow);
        actionShowActiveSFPrevious->setObjectName(QStringLiteral("actionShowActiveSFPrevious"));
        actionShowActiveSFPrevious->setShortcutContext(Qt::ApplicationShortcut);
        actionShowActiveSFNext = new QAction(MainWindow);
        actionShowActiveSFNext->setObjectName(QStringLiteral("actionShowActiveSFNext"));
        actionPointPairsAlign = new QAction(MainWindow);
        actionPointPairsAlign->setObjectName(QStringLiteral("actionPointPairsAlign"));
        QIcon icon46;
        icon46.addFile(QStringLiteral(":/CC/images/ccAlign.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointPairsAlign->setIcon(icon46);
        actionAddConstantSF = new QAction(MainWindow);
        actionAddConstantSF->setObjectName(QStringLiteral("actionAddConstantSF"));
        QIcon icon47;
        icon47.addFile(QStringLiteral(":/CC/images/ccAddConstSF.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddConstantSF->setIcon(icon47);
        actionExportCoordToSF = new QAction(MainWindow);
        actionExportCoordToSF->setObjectName(QStringLiteral("actionExportCoordToSF"));
        actionSubdivideMesh = new QAction(MainWindow);
        actionSubdivideMesh->setObjectName(QStringLiteral("actionSubdivideMesh"));
        actionToggleShowName = new QAction(MainWindow);
        actionToggleShowName->setObjectName(QStringLiteral("actionToggleShowName"));
        actionToggleShowName->setShortcutContext(Qt::ApplicationShortcut);
        actionPrimitiveFactory = new QAction(MainWindow);
        actionPrimitiveFactory->setObjectName(QStringLiteral("actionPrimitiveFactory"));
        QIcon icon48;
        icon48.addFile(QStringLiteral(":/CC/images/dbMiscGeomSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrimitiveFactory->setIcon(icon48);
        actionToggleMaterials = new QAction(MainWindow);
        actionToggleMaterials->setObjectName(QStringLiteral("actionToggleMaterials"));
        actionToggleMaterials->setShortcutContext(Qt::ApplicationShortcut);
        actionSetOrthoView = new QAction(MainWindow);
        actionSetOrthoView->setObjectName(QStringLiteral("actionSetOrthoView"));
        QIcon icon49;
        icon49.addFile(QStringLiteral(":/CC/images/ccOrthoMode32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetOrthoView->setIcon(icon49);
        actionSetCenteredPerspectiveView = new QAction(MainWindow);
        actionSetCenteredPerspectiveView->setObjectName(QStringLiteral("actionSetCenteredPerspectiveView"));
        actionSetCenteredPerspectiveView->setIcon(icon35);
        actionSetViewerPerspectiveView = new QAction(MainWindow);
        actionSetViewerPerspectiveView->setObjectName(QStringLiteral("actionSetViewerPerspectiveView"));
        actionSetViewerPerspectiveView->setIcon(icon36);
        actionSetPivotAlwaysOn = new QAction(MainWindow);
        actionSetPivotAlwaysOn->setObjectName(QStringLiteral("actionSetPivotAlwaysOn"));
        QIcon icon50;
        icon50.addFile(QStringLiteral(":/CC/images/ccPivotOn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetPivotAlwaysOn->setIcon(icon50);
        actionSetPivotRotationOnly = new QAction(MainWindow);
        actionSetPivotRotationOnly->setObjectName(QStringLiteral("actionSetPivotRotationOnly"));
        QIcon icon51;
        icon51.addFile(QStringLiteral(":/CC/images/ccPivotAuto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetPivotRotationOnly->setIcon(icon51);
        actionSetPivotOff = new QAction(MainWindow);
        actionSetPivotOff->setObjectName(QStringLiteral("actionSetPivotOff"));
        QIcon icon52;
        icon52.addFile(QStringLiteral(":/CC/images/ccPivotOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetPivotOff->setIcon(icon52);
        actionSetViewIso1 = new QAction(MainWindow);
        actionSetViewIso1->setObjectName(QStringLiteral("actionSetViewIso1"));
        QIcon icon53;
        icon53.addFile(QStringLiteral(":/CC/images/ccViewIso1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewIso1->setIcon(icon53);
        actionSetViewIso1->setShortcutContext(Qt::ApplicationShortcut);
        actionSetViewIso2 = new QAction(MainWindow);
        actionSetViewIso2->setObjectName(QStringLiteral("actionSetViewIso2"));
        QIcon icon54;
        icon54.addFile(QStringLiteral(":/CC/images/ccViewIso2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetViewIso2->setIcon(icon54);
        actionSetViewIso2->setShortcutContext(Qt::ApplicationShortcut);
        actionConvertTextureToColor = new QAction(MainWindow);
        actionConvertTextureToColor->setObjectName(QStringLiteral("actionConvertTextureToColor"));
        actionConvertTextureToColor->setIcon(icon5);
        actionOpenColorScalesManager = new QAction(MainWindow);
        actionOpenColorScalesManager->setObjectName(QStringLiteral("actionOpenColorScalesManager"));
        QIcon icon55;
        icon55.addFile(QStringLiteral(":/CC/images/typeSF.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenColorScalesManager->setIcon(icon55);
        actionOpenColorScalesManager->setShortcutContext(Qt::ApplicationShortcut);
        actionCrossSection = new QAction(MainWindow);
        actionCrossSection->setObjectName(QStringLiteral("actionCrossSection"));
        QIcon icon56;
        icon56.addFile(QStringLiteral(":/CC/images/ccClippingBox.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCrossSection->setIcon(icon56);
        actionEditGlobalShiftAndScale = new QAction(MainWindow);
        actionEditGlobalShiftAndScale->setObjectName(QStringLiteral("actionEditGlobalShiftAndScale"));
        actionScalarFieldFromColor = new QAction(MainWindow);
        actionScalarFieldFromColor->setObjectName(QStringLiteral("actionScalarFieldFromColor"));
        actionComputeKdTree = new QAction(MainWindow);
        actionComputeKdTree->setObjectName(QStringLiteral("actionComputeKdTree"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionAddIdField = new QAction(MainWindow);
        actionAddIdField->setObjectName(QStringLiteral("actionAddIdField"));
        actionFitFacet = new QAction(MainWindow);
        actionFitFacet->setObjectName(QStringLiteral("actionFitFacet"));
        actionAdjustZoom = new QAction(MainWindow);
        actionAdjustZoom->setObjectName(QStringLiteral("actionAdjustZoom"));
        actionSetSFAsCoord = new QAction(MainWindow);
        actionSetSFAsCoord->setObjectName(QStringLiteral("actionSetSFAsCoord"));
        actionCloseAll = new QAction(MainWindow);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        actionEditGlobalScale = new QAction(MainWindow);
        actionEditGlobalScale->setObjectName(QStringLiteral("actionEditGlobalScale"));
        actionViewFromSensor = new QAction(MainWindow);
        actionViewFromSensor->setObjectName(QStringLiteral("actionViewFromSensor"));
        actionViewFromSensor->setIcon(icon43);
        actionFindBiggestInnerRectangle = new QAction(MainWindow);
        actionFindBiggestInnerRectangle->setObjectName(QStringLiteral("actionFindBiggestInnerRectangle"));
        actionCreateGBLSensor = new QAction(MainWindow);
        actionCreateGBLSensor->setObjectName(QStringLiteral("actionCreateGBLSensor"));
        actionCreateCameraSensor = new QAction(MainWindow);
        actionCreateCameraSensor->setObjectName(QStringLiteral("actionCreateCameraSensor"));
        actionCheckPointsInsideFrustum = new QAction(MainWindow);
        actionCheckPointsInsideFrustum->setObjectName(QStringLiteral("actionCheckPointsInsideFrustum"));
        actionProjectUncertainty = new QAction(MainWindow);
        actionProjectUncertainty->setObjectName(QStringLiteral("actionProjectUncertainty"));
        actionOrientNormalsMST = new QAction(MainWindow);
        actionOrientNormalsMST->setObjectName(QStringLiteral("actionOrientNormalsMST"));
        actionOrientNormalsFM = new QAction(MainWindow);
        actionOrientNormalsFM->setObjectName(QStringLiteral("actionOrientNormalsFM"));
        actionCNETest = new QAction(MainWindow);
        actionCNETest->setObjectName(QStringLiteral("actionCNETest"));
        actionApproximateDensity = new QAction(MainWindow);
        actionApproximateDensity->setObjectName(QStringLiteral("actionApproximateDensity"));
        actionComputeDensity = new QAction(MainWindow);
        actionComputeDensity->setObjectName(QStringLiteral("actionComputeDensity"));
        actionRemoveDuplicatePoints = new QAction(MainWindow);
        actionRemoveDuplicatePoints->setObjectName(QStringLiteral("actionRemoveDuplicatePoints"));
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QStringLiteral("actionCrop"));
        actionConvertNormalToDipDir = new QAction(MainWindow);
        actionConvertNormalToDipDir->setObjectName(QStringLiteral("actionConvertNormalToDipDir"));
        actionExportCloudInfo = new QAction(MainWindow);
        actionExportCloudInfo->setObjectName(QStringLiteral("actionExportCloudInfo"));
        actionInterpolateColors = new QAction(MainWindow);
        actionInterpolateColors->setObjectName(QStringLiteral("actionInterpolateColors"));
        actionDistanceToBestFitQuadric3D = new QAction(MainWindow);
        actionDistanceToBestFitQuadric3D->setObjectName(QStringLiteral("actionDistanceToBestFitQuadric3D"));
        actionChangeColorLevels = new QAction(MainWindow);
        actionChangeColorLevels->setObjectName(QStringLiteral("actionChangeColorLevels"));
        actionResetGUIElementsPos = new QAction(MainWindow);
        actionResetGUIElementsPos->setObjectName(QStringLiteral("actionResetGUIElementsPos"));
        actionConvertToRandomRGB = new QAction(MainWindow);
        actionConvertToRandomRGB->setObjectName(QStringLiteral("actionConvertToRandomRGB"));
        actionNoiseFilter = new QAction(MainWindow);
        actionNoiseFilter->setObjectName(QStringLiteral("actionNoiseFilter"));
        actionComputeStatParams2 = new QAction(MainWindow);
        actionComputeStatParams2->setObjectName(QStringLiteral("actionComputeStatParams2"));
        actionComputeStatParams2->setIcon(icon21);
        actionMeasureMeshVolume = new QAction(MainWindow);
        actionMeasureMeshVolume->setObjectName(QStringLiteral("actionMeasureMeshVolume"));
        actionFlagMeshVertices = new QAction(MainWindow);
        actionFlagMeshVertices->setObjectName(QStringLiteral("actionFlagMeshVertices"));
        actionToggleActivation = new QAction(MainWindow);
        actionToggleActivation->setObjectName(QStringLiteral("actionToggleActivation"));
        actionToggleActivation->setShortcutContext(Qt::ApplicationShortcut);
        actionLockRotationAxis = new QAction(MainWindow);
        actionLockRotationAxis->setObjectName(QStringLiteral("actionLockRotationAxis"));
        actionLockRotationAxis->setCheckable(true);
        actionLockRotationAxis->setShortcutContext(Qt::ApplicationShortcut);
        actionCreateCloudFromEntCenters = new QAction(MainWindow);
        actionCreateCloudFromEntCenters->setObjectName(QStringLiteral("actionCreateCloudFromEntCenters"));
        actionComputeBestICPRmsMatrix = new QAction(MainWindow);
        actionComputeBestICPRmsMatrix->setObjectName(QStringLiteral("actionComputeBestICPRmsMatrix"));
        actionEnterBubbleViewMode = new QAction(MainWindow);
        actionEnterBubbleViewMode->setObjectName(QStringLiteral("actionEnterBubbleViewMode"));
        actionExtractSections = new QAction(MainWindow);
        actionExtractSections->setObjectName(QStringLiteral("actionExtractSections"));
        QIcon icon57;
        icon57.addFile(QStringLiteral(":/CC/images/dbPolylineSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtractSections->setIcon(icon57);
        actionConvertPolylinesToMesh = new QAction(MainWindow);
        actionConvertPolylinesToMesh->setObjectName(QStringLiteral("actionConvertPolylinesToMesh"));
        actionLevel = new QAction(MainWindow);
        actionLevel->setObjectName(QStringLiteral("actionLevel"));
        QIcon icon58;
        icon58.addFile(QStringLiteral(":/CC/images/ccLevel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLevel->setIcon(icon58);
        actionFitSphere = new QAction(MainWindow);
        actionFitSphere->setObjectName(QStringLiteral("actionFitSphere"));
        actionMatchScales = new QAction(MainWindow);
        actionMatchScales->setObjectName(QStringLiteral("actionMatchScales"));
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        actionDistanceMap = new QAction(MainWindow);
        actionDistanceMap->setObjectName(QStringLiteral("actionDistanceMap"));
        actionSORFilter = new QAction(MainWindow);
        actionSORFilter->setObjectName(QStringLiteral("actionSORFilter"));
        QIcon icon59;
        icon59.addFile(QStringLiteral(":/CC/images/ccSORFilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSORFilter->setIcon(icon59);
        actionEnableStereo = new QAction(MainWindow);
        actionEnableStereo->setObjectName(QStringLiteral("actionEnableStereo"));
        actionEnableStereo->setCheckable(true);
        QIcon icon60;
        icon60.addFile(QStringLiteral(":/CC/images/ccStereo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnableStereo->setIcon(icon60);
        actionEnableStereo->setShortcutContext(Qt::ApplicationShortcut);
        actionComputePointsVisibility = new QAction(MainWindow);
        actionComputePointsVisibility->setObjectName(QStringLiteral("actionComputePointsVisibility"));
        actionCompute2HalfDimVolume = new QAction(MainWindow);
        actionCompute2HalfDimVolume->setObjectName(QStringLiteral("actionCompute2HalfDimVolume"));
        actionExclusiveFullScreen = new QAction(MainWindow);
        actionExclusiveFullScreen->setObjectName(QStringLiteral("actionExclusiveFullScreen"));
        actionExclusiveFullScreen->setCheckable(true);
        actionExclusiveFullScreen->setIcon(icon3);
        actionExclusiveFullScreen->setShortcutContext(Qt::ApplicationShortcut);
        actionEnableVisualDebugTraces = new QAction(MainWindow);
        actionEnableVisualDebugTraces->setObjectName(QStringLiteral("actionEnableVisualDebugTraces"));
        actionRGBToGreyScale = new QAction(MainWindow);
        actionRGBToGreyScale->setObjectName(QStringLiteral("actionRGBToGreyScale"));
        actionTracePolyline = new QAction(MainWindow);
        actionTracePolyline->setObjectName(QStringLiteral("actionTracePolyline"));
        QIcon icon61;
        icon61.addFile(QStringLiteral(":/CC/images/ccTracePolyline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTracePolyline->setIcon(icon61);
        actionEnableQtWarnings = new QAction(MainWindow);
        actionEnableQtWarnings->setObjectName(QStringLiteral("actionEnableQtWarnings"));
        actionEnableQtWarnings->setCheckable(true);
        actionGlobalShiftSettings = new QAction(MainWindow);
        actionGlobalShiftSettings->setObjectName(QStringLiteral("actionGlobalShiftSettings"));
        actionEnableCameraLink = new QAction(MainWindow);
        actionEnableCameraLink->setObjectName(QStringLiteral("actionEnableCameraLink"));
        actionEnableCameraLink->setCheckable(true);
        actionShowWaveDialog = new QAction(MainWindow);
        actionShowWaveDialog->setObjectName(QStringLiteral("actionShowWaveDialog"));
        actionCreatePlane = new QAction(MainWindow);
        actionCreatePlane->setObjectName(QStringLiteral("actionCreatePlane"));
        actionEditPlane = new QAction(MainWindow);
        actionEditPlane->setObjectName(QStringLiteral("actionEditPlane"));
        actionCreateSurfaceBetweenTwoPolylines = new QAction(MainWindow);
        actionCreateSurfaceBetweenTwoPolylines->setObjectName(QStringLiteral("actionCreateSurfaceBetweenTwoPolylines"));
        actionMeshTwoPolylines = new QAction(MainWindow);
        actionMeshTwoPolylines->setObjectName(QStringLiteral("actionMeshTwoPolylines"));
        actionFitPlaneProxy = new QAction(MainWindow);
        actionFitPlaneProxy->setObjectName(QStringLiteral("actionFitPlaneProxy"));
        actionEnhanceRGBWithIntensities = new QAction(MainWindow);
        actionEnhanceRGBWithIntensities->setObjectName(QStringLiteral("actionEnhanceRGBWithIntensities"));
        actionMeshScanGrids = new QAction(MainWindow);
        actionMeshScanGrids->setObjectName(QStringLiteral("actionMeshScanGrids"));
        actionAutoPickRotationCenter = new QAction(MainWindow);
        actionAutoPickRotationCenter->setObjectName(QStringLiteral("actionAutoPickRotationCenter"));
        actionAutoPickRotationCenter->setCheckable(true);
        actionAutoPickRotationCenter->setChecked(true);
        QIcon icon62;
        icon62.addFile(QStringLiteral(":/CC/images/ccPickCenterAuto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAutoPickRotationCenter->setIcon(icon62);
        actionAutoPickRotationCenter->setShortcutContext(Qt::ApplicationShortcut);
        actionShowCursor3DCoordinates = new QAction(MainWindow);
        actionShowCursor3DCoordinates->setObjectName(QStringLiteral("actionShowCursor3DCoordinates"));
        actionShowCursor3DCoordinates->setCheckable(true);
        actionDeleteScanGrid = new QAction(MainWindow);
        actionDeleteScanGrid->setObjectName(QStringLiteral("actionDeleteScanGrid"));
        actionCompressFWFData = new QAction(MainWindow);
        actionCompressFWFData->setObjectName(QStringLiteral("actionCompressFWFData"));
        actionInterpolateSFs = new QAction(MainWindow);
        actionInterpolateSFs->setObjectName(QStringLiteral("actionInterpolateSFs"));
        actionExportPlaneInfo = new QAction(MainWindow);
        actionExportPlaneInfo->setObjectName(QStringLiteral("actionExportPlaneInfo"));
        actionLock_rotation_about_arbitrary_axis = new QAction(MainWindow);
        actionLock_rotation_about_arbitrary_axis->setObjectName(QStringLiteral("actionLock_rotation_about_arbitrary_axis"));
        actionSamplePointsOnPolyline = new QAction(MainWindow);
        actionSamplePointsOnPolyline->setObjectName(QStringLiteral("actionSamplePointsOnPolyline"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 28));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDisplay = new QMenu(menubar);
        menuDisplay->setObjectName(QStringLiteral("menuDisplay"));
        menuToolbars = new QMenu(menuDisplay);
        menuToolbars->setObjectName(QStringLiteral("menuToolbars"));
        menuLights = new QMenu(menuDisplay);
        menuLights->setObjectName(QStringLiteral("menuLights"));
        QIcon icon63;
        icon63.addFile(QStringLiteral(":/CC/images/ccSunLight.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLights->setIcon(icon63);
        menuActiveScalarField = new QMenu(menuDisplay);
        menuActiveScalarField->setObjectName(QStringLiteral("menuActiveScalarField"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuScalarFields = new QMenu(menuEdit);
        menuScalarFields->setObjectName(QStringLiteral("menuScalarFields"));
        menuColors = new QMenu(menuEdit);
        menuColors->setObjectName(QStringLiteral("menuColors"));
        menuNormals = new QMenu(menuEdit);
        menuNormals->setObjectName(QStringLiteral("menuNormals"));
        menuOrientNormals = new QMenu(menuNormals);
        menuOrientNormals->setObjectName(QStringLiteral("menuOrientNormals"));
        menuConvert_to = new QMenu(menuNormals);
        menuConvert_to->setObjectName(QStringLiteral("menuConvert_to"));
        menuOctree = new QMenu(menuEdit);
        menuOctree->setObjectName(QStringLiteral("menuOctree"));
        menuMesh = new QMenu(menuEdit);
        menuMesh->setObjectName(QStringLiteral("menuMesh"));
        menuMeshScalarField = new QMenu(menuMesh);
        menuMeshScalarField->setObjectName(QStringLiteral("menuMeshScalarField"));
        menuSensors = new QMenu(menuEdit);
        menuSensors->setObjectName(QStringLiteral("menuSensors"));
        menuGroundBasedLidar = new QMenu(menuSensors);
        menuGroundBasedLidar->setObjectName(QStringLiteral("menuGroundBasedLidar"));
        QIcon icon64;
        icon64.addFile(QStringLiteral(":/CC/images/dbGBLSensorSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuGroundBasedLidar->setIcon(icon64);
        menuCameraSensor = new QMenu(menuSensors);
        menuCameraSensor->setObjectName(QStringLiteral("menuCameraSensor"));
        QIcon icon65;
        icon65.addFile(QStringLiteral(":/CC/images/dbCamSensorSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuCameraSensor->setIcon(icon65);
        menuToggle = new QMenu(menuEdit);
        menuToggle->setObjectName(QStringLiteral("menuToggle"));
        menuWaveform = new QMenu(menuEdit);
        menuWaveform->setObjectName(QStringLiteral("menuWaveform"));
        menuPlane = new QMenu(menuEdit);
        menuPlane->setObjectName(QStringLiteral("menuPlane"));
        menuGrid = new QMenu(menuEdit);
        menuGrid->setObjectName(QStringLiteral("menuGrid"));
        menuPolyline = new QMenu(menuEdit);
        menuPolyline->setObjectName(QStringLiteral("menuPolyline"));
        menu3DViews = new QMenu(menubar);
        menu3DViews->setObjectName(QStringLiteral("menu3DViews"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuSegmentation = new QMenu(menuTools);
        menuSegmentation->setObjectName(QStringLiteral("menuSegmentation"));
        menuProjection = new QMenu(menuTools);
        menuProjection->setObjectName(QStringLiteral("menuProjection"));
        menuStatistics = new QMenu(menuTools);
        menuStatistics->setObjectName(QStringLiteral("menuStatistics"));
        menuDistances = new QMenu(menuTools);
        menuDistances->setObjectName(QStringLiteral("menuDistances"));
        menuRegistration = new QMenu(menuTools);
        menuRegistration->setObjectName(QStringLiteral("menuRegistration"));
        menuOther = new QMenu(menuTools);
        menuOther->setObjectName(QStringLiteral("menuOther"));
        menuSandBox = new QMenu(menuTools);
        menuSandBox->setObjectName(QStringLiteral("menuSandBox"));
        menuFit = new QMenu(menuTools);
        menuFit->setObjectName(QStringLiteral("menuFit"));
        menuClean = new QMenu(menuTools);
        menuClean->setObjectName(QStringLiteral("menuClean"));
        menuVolume = new QMenu(menuTools);
        menuVolume->setObjectName(QStringLiteral("menuVolume"));
        menuBatchExport = new QMenu(menuTools);
        menuBatchExport->setObjectName(QStringLiteral("menuBatchExport"));
        MainWindow->setMenuBar(menubar);
        DockableDBTree = new QDockWidget(MainWindow);
        DockableDBTree->setObjectName(QStringLiteral("DockableDBTree"));
        DockableDBTree->setMinimumSize(QSize(146, 175));
        DockableDBTree->setFloating(false);
        DockableDBTree->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        vboxLayout = new QVBoxLayout(dockWidgetContents);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        dbTreeView = new ccCustomQTreeView(dockWidgetContents);
        dbTreeView->setObjectName(QStringLiteral("dbTreeView"));
        dbTreeView->setStyleSheet(QLatin1String("QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/CC/images/QTreeView/vline.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/CC/images/QTreeView/branch-more.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/CC/images/QTreeView/branch-end.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"        border-image: none;\n"
"        image: url(:/CC/images/QTreeView/branch-closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings  {\n"
"        border-image: none;\n"
"        image: url(:/CC/images/QTreeView/branch-open.png);\n"
"}"));
        dbTreeView->setDragEnabled(true);
        dbTreeView->setDragDropMode(QAbstractItemView::InternalMove);
        dbTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        dbTreeView->setUniformRowHeights(true);

        vboxLayout->addWidget(dbTreeView);

        DockableDBTree->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DockableDBTree);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBarView = new QToolBar(MainWindow);
        toolBarView->setObjectName(QStringLiteral("toolBarView"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBarView);
        DockableConsole = new QDockWidget(MainWindow);
        DockableConsole->setObjectName(QStringLiteral("DockableConsole"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DockableConsole->sizePolicy().hasHeightForWidth());
        DockableConsole->setSizePolicy(sizePolicy1);
        DockableConsole->setMinimumSize(QSize(91, 128));
        DockableConsole->setMaximumSize(QSize(524287, 524287));
        DockableConsole->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
        DockableConsole->setAllowedAreas(Qt::BottomDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        vboxLayout1 = new QVBoxLayout(dockWidgetContents_2);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        consoleWidget = new ccCustomQListWidget(dockWidgetContents_2);
        consoleWidget->setObjectName(QStringLiteral("consoleWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(consoleWidget->sizePolicy().hasHeightForWidth());
        consoleWidget->setSizePolicy(sizePolicy2);
        consoleWidget->setMinimumSize(QSize(0, 80));
        consoleWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        consoleWidget->setProperty("showDropIndicator", QVariant(false));
        consoleWidget->setAlternatingRowColors(true);
        consoleWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        vboxLayout1->addWidget(consoleWidget);

        DockableConsole->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), DockableConsole);
        toolBarMainTools = new QToolBar(MainWindow);
        toolBarMainTools->setObjectName(QStringLiteral("toolBarMainTools"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarMainTools);
        toolBarSFTools = new QToolBar(MainWindow);
        toolBarSFTools->setObjectName(QStringLiteral("toolBarSFTools"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarSFTools);
        DockableProperties = new QDockWidget(MainWindow);
        DockableProperties->setObjectName(QStringLiteral("DockableProperties"));
        DockableProperties->setMinimumSize(QSize(109, 135));
        DockableProperties->setFloating(false);
        DockableProperties->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        vboxLayout2 = new QVBoxLayout(dockWidgetContents_4);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        propertiesTreeView = new QTreeView(dockWidgetContents_4);
        propertiesTreeView->setObjectName(QStringLiteral("propertiesTreeView"));
        propertiesTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        propertiesTreeView->setProperty("showDropIndicator", QVariant(false));
        propertiesTreeView->setAlternatingRowColors(true);
        propertiesTreeView->setSelectionMode(QAbstractItemView::NoSelection);
        propertiesTreeView->setRootIsDecorated(false);
        propertiesTreeView->setItemsExpandable(false);
        propertiesTreeView->setAllColumnsShowFocus(true);
        propertiesTreeView->setExpandsOnDoubleClick(false);
        propertiesTreeView->header()->setDefaultSectionSize(200);

        vboxLayout2->addWidget(propertiesTreeView);

        DockableProperties->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DockableProperties);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuDisplay->menuAction());
        menubar->addAction(menu3DViews->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionGlobalShiftSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionPrimitiveFactory);
        menuFile->addSeparator();
        menuFile->addAction(actionCloseAll);
        menuFile->addAction(actionQuit);
        menuFile->addSeparator();
        menuDisplay->addAction(actionFullScreen);
        menuDisplay->addAction(actionExclusiveFullScreen);
        menuDisplay->addAction(actionRefresh);
        menuDisplay->addAction(actionToggleCenteredPerspective);
        menuDisplay->addAction(actionToggleViewerBasedPerspective);
        menuDisplay->addAction(actionShowCursor3DCoordinates);
        menuDisplay->addAction(actionLockRotationAxis);
        menuDisplay->addAction(actionEnterBubbleViewMode);
        menuDisplay->addAction(actionEnableCameraLink);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionRenderToFile);
        menuDisplay->addAction(actionDisplayOptions);
        menuDisplay->addAction(actionEditCamera);
        menuDisplay->addAction(actionSaveViewportAsObject);
        menuDisplay->addAction(actionAdjustZoom);
        menuDisplay->addAction(actionTestFrameRate);
        menuDisplay->addSeparator();
        menuDisplay->addAction(menuLights->menuAction());
        menuDisplay->addAction(menuActiveScalarField->menuAction());
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionConsole);
        menuDisplay->addAction(menuToolbars->menuAction());
        menuDisplay->addAction(actionResetGUIElementsPos);
        menuToolbars->addAction(actionDisplayMainTools);
        menuToolbars->addAction(actionDisplayScalarFieldsTools);
        menuToolbars->addAction(actionDisplayViewTools);
        menuLights->addAction(actionToggleSunLight);
        menuLights->addAction(actionToggleCustomLight);
        menuActiveScalarField->addAction(actionToggleActiveSFColorScale);
        menuActiveScalarField->addAction(actionShowActiveSFPrevious);
        menuActiveScalarField->addAction(actionShowActiveSFNext);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutPlugins);
        menuHelp->addSeparator();
        menuHelp->addAction(actionEnableQtWarnings);
        menuEdit->addAction(menuColors->menuAction());
        menuEdit->addAction(menuNormals->menuAction());
        menuEdit->addAction(menuOctree->menuAction());
        menuEdit->addAction(menuGrid->menuAction());
        menuEdit->addAction(menuMesh->menuAction());
        menuEdit->addAction(menuPolyline->menuAction());
        menuEdit->addAction(menuPlane->menuAction());
        menuEdit->addAction(menuSensors->menuAction());
        menuEdit->addAction(menuScalarFields->menuAction());
        menuEdit->addAction(menuWaveform->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionClone);
        menuEdit->addAction(actionMerge);
        menuEdit->addAction(actionSubsample);
        menuEdit->addAction(actionApplyTransformation);
        menuEdit->addAction(actionApplyScale);
        menuEdit->addSeparator();
        menuEdit->addAction(actionTranslateRotate);
        menuEdit->addAction(actionSegment);
        menuEdit->addAction(actionCrop);
        menuEdit->addSeparator();
        menuEdit->addAction(actionEditGlobalShiftAndScale);
        menuEdit->addSeparator();
        menuEdit->addAction(menuToggle->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete);
        menuScalarFields->addAction(actionShowHistogram);
        menuScalarFields->addAction(actionComputeStatParams);
        menuScalarFields->addSeparator();
        menuScalarFields->addAction(actionSFGradient);
        menuScalarFields->addAction(actionGaussianFilter);
        menuScalarFields->addAction(actionBilateralFilter);
        menuScalarFields->addAction(actionFilterByValue);
        menuScalarFields->addAction(actionConvertToRGB);
        menuScalarFields->addAction(actionConvertToRandomRGB);
        menuScalarFields->addAction(actionRenameSF);
        menuScalarFields->addSeparator();
        menuScalarFields->addAction(actionAddConstantSF);
        menuScalarFields->addAction(actionAddIdField);
        menuScalarFields->addAction(actionExportCoordToSF);
        menuScalarFields->addAction(actionSetSFAsCoord);
        menuScalarFields->addAction(actionInterpolateSFs);
        menuScalarFields->addAction(actionScalarFieldArithmetic);
        menuScalarFields->addSeparator();
        menuScalarFields->addAction(actionOpenColorScalesManager);
        menuScalarFields->addSeparator();
        menuScalarFields->addAction(actionDeleteScalarField);
        menuScalarFields->addAction(actionDeleteAllSF);
        menuScalarFields->addSeparator();
        menuColors->addAction(actionSetUniqueColor);
        menuColors->addAction(actionColorize);
        menuColors->addAction(actionChangeColorLevels);
        menuColors->addAction(actionSetColorGradient);
        menuColors->addAction(actionRGBToGreyScale);
        menuColors->addAction(actionScalarFieldFromColor);
        menuColors->addAction(actionInterpolateColors);
        menuColors->addAction(actionEnhanceRGBWithIntensities);
        menuColors->addSeparator();
        menuColors->addAction(actionClearColor);
        menuNormals->addAction(actionComputeNormals);
        menuNormals->addAction(actionInvertNormals);
        menuNormals->addAction(menuOrientNormals->menuAction());
        menuNormals->addAction(menuConvert_to->menuAction());
        menuNormals->addSeparator();
        menuNormals->addAction(actionClearNormals);
        menuOrientNormals->addAction(actionOrientNormalsMST);
        menuOrientNormals->addAction(actionOrientNormalsFM);
        menuConvert_to->addAction(actionConvertNormalToHSV);
        menuConvert_to->addAction(actionConvertNormalToDipDir);
        menuOctree->addAction(actionComputeOctree);
        menuOctree->addSeparator();
        menuOctree->addAction(actionResampleWithOctree);
        menuMesh->addAction(actionComputeMeshAA);
        menuMesh->addAction(actionComputeMeshLS);
        menuMesh->addAction(actionMeshTwoPolylines);
        menuMesh->addAction(actionMeshScanGrids);
        menuMesh->addSeparator();
        menuMesh->addAction(actionConvertTextureToColor);
        menuMesh->addAction(actionSamplePointsOnMesh);
        menuMesh->addAction(actionSmoothMeshLaplacian);
        menuMesh->addAction(actionSubdivideMesh);
        menuMesh->addSeparator();
        menuMesh->addAction(actionMeasureMeshSurface);
        menuMesh->addAction(actionMeasureMeshVolume);
        menuMesh->addAction(actionFlagMeshVertices);
        menuMesh->addSeparator();
        menuMesh->addAction(menuMeshScalarField->menuAction());
        menuMeshScalarField->addAction(actionSmoothMeshSF);
        menuMeshScalarField->addAction(actionEnhanceMeshSF);
        menuSensors->addAction(actionModifySensor);
        menuSensors->addSeparator();
        menuSensors->addAction(menuGroundBasedLidar->menuAction());
        menuSensors->addAction(menuCameraSensor->menuAction());
        menuSensors->addSeparator();
        menuSensors->addAction(actionViewFromSensor);
        menuSensors->addAction(actionComputeDistancesFromSensor);
        menuSensors->addAction(actionComputeScatteringAngles);
        menuGroundBasedLidar->addAction(actionCreateGBLSensor);
        menuGroundBasedLidar->addSeparator();
        menuGroundBasedLidar->addAction(actionShowDepthBuffer);
        menuGroundBasedLidar->addAction(actionExportDepthBuffer);
        menuGroundBasedLidar->addAction(actionComputePointsVisibility);
        menuCameraSensor->addAction(actionCreateCameraSensor);
        menuCameraSensor->addSeparator();
        menuCameraSensor->addAction(actionProjectUncertainty);
        menuCameraSensor->addAction(actionCheckPointsInsideFrustum);
        menuToggle->addAction(actionToggleActivation);
        menuToggle->addAction(actionToggleVisibility);
        menuToggle->addAction(actionToggleColors);
        menuToggle->addAction(actionToggleNormals);
        menuToggle->addAction(actionToggleSF);
        menuToggle->addAction(actionToggleMaterials);
        menuToggle->addAction(actionToggleShowName);
        menuWaveform->addAction(actionShowWaveDialog);
        menuWaveform->addAction(actionCompressFWFData);
        menuPlane->addAction(actionCreatePlane);
        menuPlane->addAction(actionFitPlaneProxy);
        menuPlane->addAction(actionEditPlane);
        menuGrid->addAction(actionDeleteScanGrid);
        menuGrid->addAction(actionMeshScanGrids);
        menuPolyline->addAction(actionSamplePointsOnPolyline);
        menu3DViews->addAction(actionNew3DView);
        menu3DViews->addSeparator();
        menu3DViews->addAction(actionZoomIn);
        menu3DViews->addAction(actionZoomOut);
        menu3DViews->addSeparator();
        menu3DViews->addAction(actionClose3DView);
        menu3DViews->addAction(actionCloseAll3DViews);
        menu3DViews->addSeparator();
        menu3DViews->addAction(actionTile3DViews);
        menu3DViews->addAction(actionCascade3DViews);
        menu3DViews->addSeparator();
        menu3DViews->addAction(actionNext3DView);
        menu3DViews->addAction(actionPrevious3DView);
        menuTools->addAction(menuClean->menuAction());
        menuTools->addAction(menuProjection->menuAction());
        menuTools->addAction(menuRegistration->menuAction());
        menuTools->addAction(menuDistances->menuAction());
        menuTools->addAction(menuVolume->menuAction());
        menuTools->addAction(menuStatistics->menuAction());
        menuTools->addAction(menuSegmentation->menuAction());
        menuTools->addAction(menuFit->menuAction());
        menuTools->addAction(menuBatchExport->menuAction());
        menuTools->addAction(menuOther->menuAction());
        menuTools->addSeparator();
        menuTools->addAction(actionLevel);
        menuTools->addAction(actionPointPicking);
        menuTools->addAction(actionPointListPicking);
        menuTools->addAction(actionTracePolyline);
        menuTools->addSeparator();
        menuTools->addAction(menuSandBox->menuAction());
        menuTools->addSeparator();
        menuSegmentation->addAction(actionLabelConnectedComponents);
        menuSegmentation->addAction(actionCrossSection);
        menuSegmentation->addAction(actionExtractSections);
        menuSegmentation->addSeparator();
        menuSegmentation->addAction(actionKMeans);
        menuSegmentation->addAction(actionFrontPropagation);
        menuProjection->addAction(actionUnroll);
        menuProjection->addAction(actionRasterize);
        menuProjection->addAction(actionConvertPolylinesToMesh);
        menuProjection->addAction(actionExportCoordToSF);
        menuProjection->addAction(actionCreateSurfaceBetweenTwoPolylines);
        menuStatistics->addAction(actionStatisticalTest);
        menuStatistics->addAction(actionComputeStatParams2);
        menuDistances->addAction(actionCloudCloudDist);
        menuDistances->addAction(actionCloudMeshDist);
        menuDistances->addAction(actionCPS);
        menuRegistration->addAction(actionMatchBBCenters);
        menuRegistration->addAction(actionMatchScales);
        menuRegistration->addAction(actionPointPairsAlign);
        menuRegistration->addAction(actionRegister);
        menuOther->addAction(actionComputeDensity);
        menuOther->addAction(actionCurvature);
        menuOther->addAction(actionRoughness);
        menuOther->addAction(actionRemoveDuplicatePoints);
        menuSandBox->addAction(actionComputeKdTree);
        menuSandBox->addSeparator();
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionComputeBestFitBB);
        menuSandBox->addAction(actionDistanceToBestFitQuadric3D);
        menuSandBox->addAction(actionDistanceMap);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionAlign);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionSNETest);
        menuSandBox->addAction(actionCNETest);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionFindBiggestInnerRectangle);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionCreateCloudFromEntCenters);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionComputeBestICPRmsMatrix);
        menuSandBox->addSeparator();
        menuSandBox->addAction(actionEnableVisualDebugTraces);
        menuFit->addAction(actionFitPlane);
        menuFit->addAction(actionFitSphere);
        menuFit->addAction(actionFitFacet);
        menuFit->addAction(actionFitQuadric);
        menuClean->addAction(actionSORFilter);
        menuClean->addAction(actionNoiseFilter);
        menuVolume->addAction(actionCompute2HalfDimVolume);
        menuBatchExport->addAction(actionExportCloudInfo);
        menuBatchExport->addAction(actionExportPlaneInfo);
        toolBarView->addAction(actionDisplayOptions);
        toolBarView->addAction(actionEditCamera);
        toolBarView->addAction(actionGlobalZoom);
        toolBarView->addAction(actionPickRotationCenter);
        toolBarView->addAction(actionAutoPickRotationCenter);
        toolBarView->addAction(actionLevel);
        toolBarView->addAction(actionZoomAndCenter);
        toolBarView->addAction(actionSetViewTop);
        toolBarView->addAction(actionSetViewFront);
        toolBarView->addAction(actionSetViewLeft);
        toolBarView->addAction(actionSetViewBack);
        toolBarView->addAction(actionSetViewRight);
        toolBarView->addAction(actionSetViewBottom);
        toolBarView->addAction(actionSetViewIso1);
        toolBarView->addAction(actionSetViewIso2);
        toolBarView->addAction(actionEnableStereo);
        toolBarMainTools->addAction(actionOpen);
        toolBarMainTools->addAction(actionSave);
        toolBarMainTools->addSeparator();
        toolBarMainTools->addAction(actionPointPicking);
        toolBarMainTools->addAction(actionPointListPicking);
        toolBarMainTools->addAction(actionTracePolyline);
        toolBarMainTools->addAction(actionClone);
        toolBarMainTools->addAction(actionMerge);
        toolBarMainTools->addAction(actionDelete);
        toolBarMainTools->addSeparator();
        toolBarMainTools->addAction(actionPointPairsAlign);
        toolBarMainTools->addAction(actionRegister);
        toolBarMainTools->addAction(actionSubsample);
        toolBarMainTools->addAction(actionSamplePointsOnMesh);
        toolBarMainTools->addAction(actionCloudCloudDist);
        toolBarMainTools->addAction(actionCloudMeshDist);
        toolBarMainTools->addAction(actionLabelConnectedComponents);
        toolBarMainTools->addAction(actionPrimitiveFactory);
        toolBarMainTools->addAction(actionRasterize);
        toolBarMainTools->addAction(actionSORFilter);
        toolBarMainTools->addSeparator();
        toolBarMainTools->addAction(actionSegment);
        toolBarMainTools->addAction(actionTranslateRotate);
        toolBarMainTools->addAction(actionCrossSection);
        toolBarMainTools->addAction(actionExtractSections);
        toolBarSFTools->addAction(actionShowHistogram);
        toolBarSFTools->addAction(actionComputeStatParams);
        toolBarSFTools->addAction(actionFilterByValue);
        toolBarSFTools->addAction(actionDeleteScalarField);
        toolBarSFTools->addAction(actionAddConstantSF);
        toolBarSFTools->addAction(actionScalarFieldArithmetic);
        toolBarSFTools->addAction(actionOpenColorScalesManager);

        retranslateUi(MainWindow);
        QObject::connect(actionConsole, SIGNAL(triggered(bool)), DockableConsole, SLOT(setVisible(bool)));
        QObject::connect(DockableConsole, SIGNAL(visibilityChanged(bool)), actionConsole, SLOT(setChecked(bool)));
        QObject::connect(actionDisplayMainTools, SIGNAL(toggled(bool)), toolBarMainTools, SLOT(setVisible(bool)));
        QObject::connect(actionDisplayScalarFieldsTools, SIGNAL(toggled(bool)), toolBarSFTools, SLOT(setVisible(bool)));
        QObject::connect(actionDisplayViewTools, SIGNAL(toggled(bool)), toolBarView, SLOT(setVisible(bool)));
        QObject::connect(actionFitPlaneProxy, SIGNAL(triggered()), actionFitPlane, SLOT(trigger()));
        QObject::connect(actionCreateSurfaceBetweenTwoPolylines, SIGNAL(triggered()), actionMeshTwoPolylines, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CloudCompare", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "&\346\211\223\345\274\200", nullptr));
        actionOpen->setIconText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "Open", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current entity", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "Save current entity", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_STATUSTIP
        actionQuit->setStatusTip(QApplication::translate("MainWindow", "Quit", nullptr));
#endif // QT_NO_STATUSTIP
        actionFullScreen->setText(QApplication::translate("MainWindow", "&Full screen", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFullScreen->setToolTip(QApplication::translate("MainWindow", "Switch to full screen", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFullScreen->setStatusTip(QApplication::translate("MainWindow", "Switch to full screen", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionFullScreen->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionFullScreen->setShortcut(QApplication::translate("MainWindow", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisplayOptions->setText(QApplication::translate("MainWindow", "Display settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisplayOptions->setToolTip(QApplication::translate("MainWindow", "Display settings", nullptr));
#endif // QT_NO_TOOLTIP
        actionHelp->setText(QApplication::translate("MainWindow", "&Help", nullptr));
#ifndef QT_NO_STATUSTIP
        actionHelp->setStatusTip(QApplication::translate("MainWindow", "Help", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "&About ...", nullptr));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "About", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetUniqueColor->setText(QApplication::translate("MainWindow", "Set unique", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetUniqueColor->setToolTip(QApplication::translate("MainWindow", "Set a unique color", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetUniqueColor->setStatusTip(QApplication::translate("MainWindow", "Set a unique color", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetUniqueColor->setShortcut(QApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetColorGradient->setText(QApplication::translate("MainWindow", "Height Ramp", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetColorGradient->setToolTip(QApplication::translate("MainWindow", "Apply a color ramp along X, Y or Z", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetColorGradient->setStatusTip(QApplication::translate("MainWindow", "Apply a color ramp along X, Y or Z", nullptr));
#endif // QT_NO_STATUSTIP
        actionComputeNormals->setText(QApplication::translate("MainWindow", "Compute", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeNormals->setToolTip(QApplication::translate("MainWindow", "Compute unsigned normals (least squares approx.)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeNormals->setStatusTip(QApplication::translate("MainWindow", "Compute unsigned normals (least squares approx.)", nullptr));
#endif // QT_NO_STATUSTIP
        actionInvertNormals->setText(QApplication::translate("MainWindow", "Invert", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInvertNormals->setToolTip(QApplication::translate("MainWindow", "Invert normals", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionInvertNormals->setStatusTip(QApplication::translate("MainWindow", "Invert normals", nullptr));
#endif // QT_NO_STATUSTIP
        actionComputeOctree->setText(QApplication::translate("MainWindow", "Compute", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeOctree->setToolTip(QApplication::translate("MainWindow", "Compute octree", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeOctree->setStatusTip(QApplication::translate("MainWindow", "Compute octree", nullptr));
#endif // QT_NO_STATUSTIP
        actionConsole->setText(QApplication::translate("MainWindow", "Console", nullptr));
#ifndef QT_NO_SHORTCUT
        actionConsole->setShortcut(QApplication::translate("MainWindow", "F8", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose3DView->setText(QApplication::translate("MainWindow", "Cl&ose", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose3DView->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionCloseAll3DViews->setText(QApplication::translate("MainWindow", "Close &All", nullptr));
        actionTile3DViews->setText(QApplication::translate("MainWindow", "&Tile", nullptr));
        actionCascade3DViews->setText(QApplication::translate("MainWindow", "&Cascade", nullptr));
        actionPrevious3DView->setText(QApplication::translate("MainWindow", "Pre&vious", nullptr));
        actionNext3DView->setText(QApplication::translate("MainWindow", "Ne&xt", nullptr));
        actionNew3DView->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew3DView->setShortcut(QApplication::translate("MainWindow", "Ctrl+F3", nullptr));
#endif // QT_NO_SHORTCUT
        actionClone->setText(QApplication::translate("MainWindow", "Clone", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClone->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Clone the selected entities</p><p><span style=\" font-style:italic;\">(yes Claire ... these are Nyan sheep!)</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionMerge->setText(QApplication::translate("MainWindow", "Merge", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMerge->setToolTip(QApplication::translate("MainWindow", "Merge multiple clouds", nullptr));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        actionRegister->setText(QApplication::translate("MainWindow", "Fine registration (ICP)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRegister->setToolTip(QApplication::translate("MainWindow", "Finely registers already (roughly) aligned entities (clouds or meshes)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRegister->setStatusTip(QApplication::translate("MainWindow", "Finely registers already (roughly) aligned entities (clouds or meshes)", nullptr));
#endif // QT_NO_STATUSTIP
        actionCloudCloudDist->setText(QApplication::translate("MainWindow", "Cloud/Cloud Dist.", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCloudCloudDist->setToolTip(QApplication::translate("MainWindow", "Compute cloud/cloud distance", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCloudCloudDist->setStatusTip(QApplication::translate("MainWindow", "Compute cloud/cloud distance", nullptr));
#endif // QT_NO_STATUSTIP
        actionCloudMeshDist->setText(QApplication::translate("MainWindow", "Cloud/Mesh Dist", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCloudMeshDist->setToolTip(QApplication::translate("MainWindow", "Compute cloud/mesh distance", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCloudMeshDist->setStatusTip(QApplication::translate("MainWindow", "Compute cloud/mesh distance", nullptr));
#endif // QT_NO_STATUSTIP
        actionStatisticalTest->setText(QApplication::translate("MainWindow", "Local Statistical test", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStatisticalTest->setToolTip(QApplication::translate("MainWindow", "Apply a local statistical test to separate noise from true differences", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionStatisticalTest->setStatusTip(QApplication::translate("MainWindow", "Apply a local statistical test to separate noise from true differences", nullptr));
#endif // QT_NO_STATUSTIP
        actionSamplePointsOnMesh->setText(QApplication::translate("MainWindow", "Sample Points", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSamplePointsOnMesh->setToolTip(QApplication::translate("MainWindow", "Sample points on a mesh", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSamplePointsOnMesh->setStatusTip(QApplication::translate("MainWindow", "Sample points on a mesh", nullptr));
#endif // QT_NO_STATUSTIP
        actionLabelConnectedComponents->setText(QApplication::translate("MainWindow", "Label Connected Comp.", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLabelConnectedComponents->setToolTip(QApplication::translate("MainWindow", "Label connected components", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionLabelConnectedComponents->setStatusTip(QApplication::translate("MainWindow", "Label connected components", nullptr));
#endif // QT_NO_STATUSTIP
        actionSegment->setText(QApplication::translate("MainWindow", "Segment", nullptr));
        actionTranslateRotate->setText(QApplication::translate("MainWindow", "Translate/rotate", nullptr));
        actionShowHistogram->setText(QApplication::translate("MainWindow", "Show histogram", nullptr));
        actionComputeStatParams->setText(QApplication::translate("MainWindow", "Compute stat. params", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeStatParams->setToolTip(QApplication::translate("MainWindow", "Fits a statistical model on the active scalar field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeStatParams->setStatusTip(QApplication::translate("MainWindow", "Fits a statistical model on the active scalar field", nullptr));
#endif // QT_NO_STATUSTIP
        actionFilterByValue->setText(QApplication::translate("MainWindow", "Filter By Value", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFilterByValue->setToolTip(QApplication::translate("MainWindow", "Filter points by value", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFilterByValue->setStatusTip(QApplication::translate("MainWindow", "Filter points by value", nullptr));
#endif // QT_NO_STATUSTIP
        actionGaussianFilter->setText(QApplication::translate("MainWindow", "Gaussian filter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionGaussianFilter->setToolTip(QApplication::translate("MainWindow", "Compute gaussian filter", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionGaussianFilter->setStatusTip(QApplication::translate("MainWindow", "Compute gaussian filter", nullptr));
#endif // QT_NO_STATUSTIP
        actionDeleteScalarField->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        actionDeleteScalarField->setIconText(QApplication::translate("MainWindow", "Delete Scalar Field", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDeleteScalarField->setToolTip(QApplication::translate("MainWindow", "Delete current scalar field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDeleteScalarField->setStatusTip(QApplication::translate("MainWindow", "Delete current scalar field", nullptr));
#endif // QT_NO_STATUSTIP
        actionScalarFieldArithmetic->setText(QApplication::translate("MainWindow", "Arithmetic", nullptr));
        actionScalarFieldArithmetic->setIconText(QApplication::translate("MainWindow", "SF arithmetic", nullptr));
#ifndef QT_NO_TOOLTIP
        actionScalarFieldArithmetic->setToolTip(QApplication::translate("MainWindow", "Add, subtract, multiply or divide two scalar fields", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionScalarFieldArithmetic->setStatusTip(QApplication::translate("MainWindow", "Add, subtract, multiply or divide two scalar fields", nullptr));
#endif // QT_NO_STATUSTIP
        actionColorize->setText(QApplication::translate("MainWindow", "Colorize", nullptr));
#ifndef QT_NO_TOOLTIP
        actionColorize->setToolTip(QApplication::translate("MainWindow", "Colorize entity (lightness values are unchanged)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionColorize->setStatusTip(QApplication::translate("MainWindow", "Colorize entity (lightness values are unchanged)", nullptr));
#endif // QT_NO_STATUSTIP
        actionSmoothMeshSF->setText(QApplication::translate("MainWindow", "Smooth", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSmoothMeshSF->setToolTip(QApplication::translate("MainWindow", "Smooth mesh scalar field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSmoothMeshSF->setStatusTip(QApplication::translate("MainWindow", "Smooth mesh scalar field", nullptr));
#endif // QT_NO_STATUSTIP
        actionEnhanceMeshSF->setText(QApplication::translate("MainWindow", "Enhance", nullptr));
        actionEnhanceMeshSF->setIconText(QApplication::translate("MainWindow", "Enhance", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEnhanceMeshSF->setToolTip(QApplication::translate("MainWindow", "Enhance Scalar Field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionEnhanceMeshSF->setStatusTip(QApplication::translate("MainWindow", "Enhance Scalar Field", nullptr));
#endif // QT_NO_STATUSTIP
        actionClearColor->setText(QApplication::translate("MainWindow", "Clear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClearColor->setToolTip(QApplication::translate("MainWindow", "Clear colors", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearColor->setStatusTip(QApplication::translate("MainWindow", "Clear colors", nullptr));
#endif // QT_NO_STATUSTIP
        actionClearNormals->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        actionClearNormals->setIconText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClearNormals->setToolTip(QApplication::translate("MainWindow", "Delete normals", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearNormals->setStatusTip(QApplication::translate("MainWindow", "Delete normals", nullptr));
#endif // QT_NO_STATUSTIP
        actionResampleWithOctree->setText(QApplication::translate("MainWindow", "Resample", nullptr));
#ifndef QT_NO_TOOLTIP
        actionResampleWithOctree->setToolTip(QApplication::translate("MainWindow", "Resample entity with octree", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionResampleWithOctree->setStatusTip(QApplication::translate("MainWindow", "Resample entity with octree", nullptr));
#endif // QT_NO_STATUSTIP
        actionComputeMeshAA->setText(QApplication::translate("MainWindow", "Delaunay 2.5D (XY plane)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeMeshAA->setToolTip(QApplication::translate("MainWindow", "Compute \"2D1/2\" mesh by projecting points on the XY plane", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeMeshAA->setStatusTip(QApplication::translate("MainWindow", "Compute \"2D1/2\" mesh by projecting points on the XY plane", nullptr));
#endif // QT_NO_STATUSTIP
        actionComputeMeshLS->setText(QApplication::translate("MainWindow", "Delaunay 2.5D (best fitting plane)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeMeshLS->setToolTip(QApplication::translate("MainWindow", "Compute \"2D1/2\" mesh by projecting points on the (least squares) best fitting plane", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeMeshLS->setStatusTip(QApplication::translate("MainWindow", "Compute \"2D1/2\" mesh by projecting points on the (least squares) best fitting plane", nullptr));
#endif // QT_NO_STATUSTIP
        actionMeasureMeshSurface->setText(QApplication::translate("MainWindow", "Measure surface", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMeasureMeshSurface->setToolTip(QApplication::translate("MainWindow", "Measure mesh surface", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionMeasureMeshSurface->setStatusTip(QApplication::translate("MainWindow", "Measure mesh surface", nullptr));
#endif // QT_NO_STATUSTIP
        actionCPS->setText(QApplication::translate("MainWindow", "Closest Point Set", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCPS->setToolTip(QApplication::translate("MainWindow", "Compute closest point set", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCPS->setStatusTip(QApplication::translate("MainWindow", "Compute closest point set", nullptr));
#endif // QT_NO_STATUSTIP
        actionDeleteAllSF->setText(QApplication::translate("MainWindow", "Delete all (!)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDeleteAllSF->setToolTip(QApplication::translate("MainWindow", "Delete all scalar fields", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDeleteAllSF->setStatusTip(QApplication::translate("MainWindow", "Delete all scalar fields", nullptr));
#endif // QT_NO_STATUSTIP
        actionMultiplySF->setText(QApplication::translate("MainWindow", "Multiply", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMultiplySF->setToolTip(QApplication::translate("MainWindow", "Multiply scalar field by a constant", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionMultiplySF->setStatusTip(QApplication::translate("MainWindow", "Multiply scalar field by a constant", nullptr));
#endif // QT_NO_STATUSTIP
        actionKMeans->setText(QApplication::translate("MainWindow", "K-Means", nullptr));
#ifndef QT_NO_TOOLTIP
        actionKMeans->setToolTip(QApplication::translate("MainWindow", "classify point (K-Means applied on a scalar field)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionKMeans->setStatusTip(QApplication::translate("MainWindow", "classify point (K-Means applied on a scalar field)", nullptr));
#endif // QT_NO_STATUSTIP
        actionFrontPropagation->setText(QApplication::translate("MainWindow", "Front propagation", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFrontPropagation->setToolTip(QApplication::translate("MainWindow", "Classify points by propagating a front on a scalar field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFrontPropagation->setStatusTip(QApplication::translate("MainWindow", "Classify points by propagating a front on a scalar field", nullptr));
#endif // QT_NO_STATUSTIP
        actionApplyScale->setText(QApplication::translate("MainWindow", "Multiply/Scale", nullptr));
#ifndef QT_NO_TOOLTIP
        actionApplyScale->setToolTip(QApplication::translate("MainWindow", "Multiply coordinates (separately)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionApplyScale->setStatusTip(QApplication::translate("MainWindow", "Multiply coordinates (separately)", nullptr));
#endif // QT_NO_STATUSTIP
        actionMatchBBCenters->setText(QApplication::translate("MainWindow", "Match bounding-box centers", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMatchBBCenters->setToolTip(QApplication::translate("MainWindow", "Synchronize selected entities bbox centers", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionMatchBBCenters->setStatusTip(QApplication::translate("MainWindow", "Synchronize selected entities bbox centers", nullptr));
#endif // QT_NO_STATUSTIP
        actionUnroll->setText(QApplication::translate("MainWindow", "Unroll", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUnroll->setToolTip(QApplication::translate("MainWindow", "Unroll entity on a cylinder or a cone", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionUnroll->setStatusTip(QApplication::translate("MainWindow", "Unroll entity on a cylinder or a cone", nullptr));
#endif // QT_NO_STATUSTIP
        actionSFGradient->setText(QApplication::translate("MainWindow", "Gradient", nullptr));
        actionZoomAndCenter->setText(QApplication::translate("MainWindow", "Zoom & Center", nullptr));
        actionZoomAndCenter->setIconText(QApplication::translate("MainWindow", "ZoomCenter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomAndCenter->setToolTip(QApplication::translate("MainWindow", "Zoom and center on selected entities (Z)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionZoomAndCenter->setStatusTip(QApplication::translate("MainWindow", "Zoom and center on selected entities (Z)", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionZoomAndCenter->setShortcut(QApplication::translate("MainWindow", "Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewTop->setText(QApplication::translate("MainWindow", "Top View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewTop->setToolTip(QApplication::translate("MainWindow", "Set top view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewTop->setStatusTip(QApplication::translate("MainWindow", "Set top view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewTop->setShortcut(QApplication::translate("MainWindow", "8", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewFront->setText(QApplication::translate("MainWindow", "Front View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewFront->setToolTip(QApplication::translate("MainWindow", "Set front view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewFront->setStatusTip(QApplication::translate("MainWindow", "Set front view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewFront->setShortcut(QApplication::translate("MainWindow", "5", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewBack->setText(QApplication::translate("MainWindow", "Back View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewBack->setToolTip(QApplication::translate("MainWindow", "Set back view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewBack->setStatusTip(QApplication::translate("MainWindow", "Set back view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewBack->setShortcut(QApplication::translate("MainWindow", "0", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewLeft->setText(QApplication::translate("MainWindow", "Left Side View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewLeft->setToolTip(QApplication::translate("MainWindow", "Set left side view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewLeft->setStatusTip(QApplication::translate("MainWindow", "Set left side view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewLeft->setShortcut(QApplication::translate("MainWindow", "4", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewRight->setText(QApplication::translate("MainWindow", "Right Side View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewRight->setToolTip(QApplication::translate("MainWindow", "Set right side view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewRight->setStatusTip(QApplication::translate("MainWindow", "Set right side view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewRight->setShortcut(QApplication::translate("MainWindow", "6", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewBottom->setText(QApplication::translate("MainWindow", "Bottom View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewBottom->setToolTip(QApplication::translate("MainWindow", "Set bottom view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewBottom->setStatusTip(QApplication::translate("MainWindow", "Set bottom view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewBottom->setShortcut(QApplication::translate("MainWindow", "2", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisplayMainTools->setText(QApplication::translate("MainWindow", "Main", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisplayMainTools->setToolTip(QApplication::translate("MainWindow", "Show/hide main toolbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDisplayMainTools->setStatusTip(QApplication::translate("MainWindow", "Show/hide main toolbar", nullptr));
#endif // QT_NO_STATUSTIP
        actionDisplayViewTools->setText(QApplication::translate("MainWindow", "View", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisplayViewTools->setToolTip(QApplication::translate("MainWindow", "Show/hide view toolbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDisplayViewTools->setStatusTip(QApplication::translate("MainWindow", "Show/hide view toolbar", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionDisplayViewTools->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionDisplayScalarFieldsTools->setText(QApplication::translate("MainWindow", "Scalar fields", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisplayScalarFieldsTools->setToolTip(QApplication::translate("MainWindow", "Show/hide scalar fields toolbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDisplayScalarFieldsTools->setStatusTip(QApplication::translate("MainWindow", "Show/hide scalar fields toolbar", nullptr));
#endif // QT_NO_STATUSTIP
        actionToggleSunLight->setText(QApplication::translate("MainWindow", "Toggle Sun Light", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleSunLight->setToolTip(QApplication::translate("MainWindow", "Toggle sun light (active window)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleSunLight->setStatusTip(QApplication::translate("MainWindow", "Toggle sun light (active window)", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionToggleSunLight->setShortcut(QApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggleCustomLight->setText(QApplication::translate("MainWindow", "Toggle Custom Light", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleCustomLight->setToolTip(QApplication::translate("MainWindow", "Toggle custom light (active window)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleCustomLight->setStatusTip(QApplication::translate("MainWindow", "Toggle custom light (active window)", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionToggleCustomLight->setShortcut(QApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        actionGlobalZoom->setText(QApplication::translate("MainWindow", "Global Zoom", nullptr));
#ifndef QT_NO_STATUSTIP
        actionGlobalZoom->setStatusTip(QApplication::translate("MainWindow", "Global Zoom", nullptr));
#endif // QT_NO_STATUSTIP
        actionToggleCenteredPerspective->setText(QApplication::translate("MainWindow", "Toggle Centered Perspective", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleCenteredPerspective->setToolTip(QApplication::translate("MainWindow", "Toggle perspective view (centered on objects) in current window", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleCenteredPerspective->setStatusTip(QApplication::translate("MainWindow", "Toggle perspective view (centered on objects) in current window", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionToggleCenteredPerspective->setShortcut(QApplication::translate("MainWindow", "F3", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggleViewerBasedPerspective->setText(QApplication::translate("MainWindow", "Toggle Viewer Based Perspective", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleViewerBasedPerspective->setToolTip(QApplication::translate("MainWindow", "Toggle perspective view (centered on viewer) in current window", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleViewerBasedPerspective->setStatusTip(QApplication::translate("MainWindow", "Toggle perspective view (centered on viewer) in current window", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionToggleViewerBasedPerspective->setShortcut(QApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionTestFrameRate->setText(QApplication::translate("MainWindow", "Test Frame Rate", nullptr));
        actionRenderToFile->setText(QApplication::translate("MainWindow", "Render to File", nullptr));
        actionAboutPlugins->setText(QApplication::translate("MainWindow", "About Plugins...", nullptr));
        actionConvertToRGB->setText(QApplication::translate("MainWindow", "Convert to RGB", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConvertToRGB->setToolTip(QApplication::translate("MainWindow", "Convert current scalar field to RGB colors", nullptr));
#endif // QT_NO_TOOLTIP
        actionShowDepthBuffer->setText(QApplication::translate("MainWindow", "Create/show depth buffer", nullptr));
        actionExportDepthBuffer->setText(QApplication::translate("MainWindow", "Export depth buffer", nullptr));
        actionModifySensor->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        actionRasterize->setText(QApplication::translate("MainWindow", "Rasterize (and contour plot)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRasterize->setToolTip(QApplication::translate("MainWindow", "Convert a cloud to 2D raster (and optionally generate the contour plot)", nullptr));
#endif // QT_NO_TOOLTIP
        actionAlign->setText(QApplication::translate("MainWindow", "Auto align clouds", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAlign->setToolTip(QApplication::translate("MainWindow", "Tries to automatically register (roughly) two points clouds", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAlign->setStatusTip(QApplication::translate("MainWindow", "Tries to automatically register (roughly) two points clouds", nullptr));
#endif // QT_NO_STATUSTIP
        actionSubsample->setText(QApplication::translate("MainWindow", "Subsample", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSubsample->setToolTip(QApplication::translate("MainWindow", "Subsample a point cloud", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSubsample->setStatusTip(QApplication::translate("MainWindow", "Subsample a point cloud", nullptr));
#endif // QT_NO_STATUSTIP
        actionLoadShader->setText(QApplication::translate("MainWindow", "Load shader", nullptr));
        actionDeleteShader->setText(QApplication::translate("MainWindow", "Delete shader", nullptr));
        actionPointPicking->setText(QApplication::translate("MainWindow", "Point picking", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPointPicking->setToolTip(QApplication::translate("MainWindow", "Point picking (point information, distance between 2 points, angles between 3 points, etc.)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPointPicking->setStatusTip(QApplication::translate("MainWindow", "Point picking (point information, distance between 2 points, angles between 3 points, etc.)", nullptr));
#endif // QT_NO_STATUSTIP
        actionComputeBestFitBB->setText(QApplication::translate("MainWindow", "Bounding box P.C.A. fit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeBestFitBB->setToolTip(QApplication::translate("MainWindow", "Makes BB fit principal components (rotates entity!)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeBestFitBB->setStatusTip(QApplication::translate("MainWindow", "Makes BB fit principal components (rotates entity!)", nullptr));
#endif // QT_NO_STATUSTIP
        actionEditCamera->setText(QApplication::translate("MainWindow", "Camera settings", nullptr));
        actionPointListPicking->setText(QApplication::translate("MainWindow", "Point list picking", nullptr));
#ifndef QT_NO_STATUSTIP
        actionPointListPicking->setStatusTip(QApplication::translate("MainWindow", "Pick several points (and export them to ASCII file, a new cloud, etc.)", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionPointListPicking->setWhatsThis(QApplication::translate("MainWindow", "Pick several points (and export them to ASCII file, a new cloud, etc.)", nullptr));
#endif // QT_NO_WHATSTHIS
        actionCurvature->setText(QApplication::translate("MainWindow", "Curvature", nullptr));
        actionRoughness->setText(QApplication::translate("MainWindow", "Roughness", nullptr));
        actionFitPlane->setText(QApplication::translate("MainWindow", "Plane", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFitPlane->setToolTip(QApplication::translate("MainWindow", "Fit a plane on a set of point", nullptr));
#endif // QT_NO_TOOLTIP
        actionRenameSF->setText(QApplication::translate("MainWindow", "Rename", nullptr));
        actionFitQuadric->setText(QApplication::translate("MainWindow", "2.5D quadric", nullptr));
        actionSNETest->setText(QApplication::translate("MainWindow", "SNE test", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSNETest->setToolTip(QApplication::translate("MainWindow", "Spherical Neighbourhood Extraction test", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSNETest->setStatusTip(QApplication::translate("MainWindow", "Spherical Neighbourhood Extraction test", nullptr));
#endif // QT_NO_STATUSTIP
        actionToggleVisibility->setText(QApplication::translate("MainWindow", "Visibility", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleVisibility->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities visibility (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleVisibility->setShortcut(QApplication::translate("MainWindow", "V", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggleNormals->setText(QApplication::translate("MainWindow", "Normals", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleNormals->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities normals (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleNormals->setShortcut(QApplication::translate("MainWindow", "N", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggleColors->setText(QApplication::translate("MainWindow", "Colors", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleColors->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities colors (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleColors->setShortcut(QApplication::translate("MainWindow", "C", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggleSF->setText(QApplication::translate("MainWindow", "SF", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleSF->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities SF (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleSF->setShortcut(QApplication::translate("MainWindow", "S", nullptr));
#endif // QT_NO_SHORTCUT
        actionApplyTransformation->setText(QApplication::translate("MainWindow", "Apply transformation", nullptr));
#ifndef QT_NO_TOOLTIP
        actionApplyTransformation->setToolTip(QApplication::translate("MainWindow", "Apply rotation and/or translation", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionApplyTransformation->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionSmoothMeshLaplacian->setText(QApplication::translate("MainWindow", "Smooth (Laplacian)", nullptr));
        actionConvertNormalToHSV->setText(QApplication::translate("MainWindow", "HSV colors", nullptr));
        actionSaveViewportAsObject->setText(QApplication::translate("MainWindow", "Save viewport as object", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveViewportAsObject->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionPickRotationCenter->setText(QApplication::translate("MainWindow", "Pick rotation center", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPickRotationCenter->setShortcut(QApplication::translate("MainWindow", "P", nullptr));
#endif // QT_NO_SHORTCUT
        actionComputeDistancesFromSensor->setText(QApplication::translate("MainWindow", "Compute Ranges", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeDistancesFromSensor->setToolTip(QApplication::translate("MainWindow", "Compute ranges from sensor", nullptr));
#endif // QT_NO_TOOLTIP
        actionBilateralFilter->setText(QApplication::translate("MainWindow", "Bilateral filter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBilateralFilter->setToolTip(QApplication::translate("MainWindow", "Compute bilateral filter", nullptr));
#endif // QT_NO_TOOLTIP
        actionComputeScatteringAngles->setText(QApplication::translate("MainWindow", "Compute Scattering Angles", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeScatteringAngles->setToolTip(QApplication::translate("MainWindow", "Compute laser beam scattering angle for a cloud with normals", nullptr));
#endif // QT_NO_TOOLTIP
        actionToggleActiveSFColorScale->setText(QApplication::translate("MainWindow", "Toggle color scale", nullptr));
        actionToggleActiveSFColorScale->setIconText(QApplication::translate("MainWindow", "Toggle active scalar field color scale", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleActiveSFColorScale->setToolTip(QApplication::translate("MainWindow", "Toggle active scalar field color scale", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleActiveSFColorScale->setShortcut(QApplication::translate("MainWindow", "Shift+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowActiveSFPrevious->setText(QApplication::translate("MainWindow", "Show previous SF", nullptr));
        actionShowActiveSFPrevious->setIconText(QApplication::translate("MainWindow", "Show previous scalar field for active entity", nullptr));
#ifndef QT_NO_TOOLTIP
        actionShowActiveSFPrevious->setToolTip(QApplication::translate("MainWindow", "Show previous scalar field for active entity", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowActiveSFPrevious->setShortcut(QApplication::translate("MainWindow", "Shift+Up", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowActiveSFNext->setText(QApplication::translate("MainWindow", "Show next SF", nullptr));
        actionShowActiveSFNext->setIconText(QApplication::translate("MainWindow", "Show next scalar field for active entity", nullptr));
#ifndef QT_NO_TOOLTIP
        actionShowActiveSFNext->setToolTip(QApplication::translate("MainWindow", "Show next scalar field for active entity", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionShowActiveSFNext->setShortcut(QApplication::translate("MainWindow", "Shift+Down", nullptr));
#endif // QT_NO_SHORTCUT
        actionPointPairsAlign->setText(QApplication::translate("MainWindow", "Align (point pairs picking)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPointPairsAlign->setToolTip(QApplication::translate("MainWindow", "Aligns two clouds by picking (at least 4) equivalent point pairs", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPointPairsAlign->setStatusTip(QApplication::translate("MainWindow", "Aligns two clouds by picking (at least 4) equivalent point pairs", nullptr));
#endif // QT_NO_STATUSTIP
        actionAddConstantSF->setText(QApplication::translate("MainWindow", "Add constant SF", nullptr));
        actionExportCoordToSF->setText(QApplication::translate("MainWindow", "Export coordinate(s) to SF(s)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExportCoordToSF->setToolTip(QApplication::translate("MainWindow", "Export X, Y and/or Z coordinates to scalar field(s)", nullptr));
#endif // QT_NO_TOOLTIP
        actionSubdivideMesh->setText(QApplication::translate("MainWindow", "Subdivide", nullptr));
        actionToggleShowName->setText(QApplication::translate("MainWindow", "3D name", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleShowName->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities 3D name display (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleShowName->setShortcut(QApplication::translate("MainWindow", "D", nullptr));
#endif // QT_NO_SHORTCUT
        actionPrimitiveFactory->setText(QApplication::translate("MainWindow", "Primitive factory", nullptr));
        actionToggleMaterials->setText(QApplication::translate("MainWindow", "Materials/textures", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleMaterials->setToolTip(QApplication::translate("MainWindow", "Toggle selected entities materials/textures (recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleMaterials->setShortcut(QApplication::translate("MainWindow", "M", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetOrthoView->setText(QApplication::translate("MainWindow", "Orthographic projection", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetOrthoView->setToolTip(QApplication::translate("MainWindow", "Set orthographic projection for current 3D View", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetOrthoView->setStatusTip(QApplication::translate("MainWindow", "Set orthographic projection for current 3D View", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetCenteredPerspectiveView->setText(QApplication::translate("MainWindow", "Object-centered perspective", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetCenteredPerspectiveView->setToolTip(QApplication::translate("MainWindow", "Set object-centered perspective for current 3D View", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetCenteredPerspectiveView->setStatusTip(QApplication::translate("MainWindow", "Set object-centered perspective for current 3D View", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetViewerPerspectiveView->setText(QApplication::translate("MainWindow", "Viewer-based perspective", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewerPerspectiveView->setToolTip(QApplication::translate("MainWindow", "Set viewer-based perspective for current 3D View", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewerPerspectiveView->setStatusTip(QApplication::translate("MainWindow", "Set viewer-based perspective for current 3D View", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetPivotAlwaysOn->setText(QApplication::translate("MainWindow", "Always visible", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetPivotAlwaysOn->setToolTip(QApplication::translate("MainWindow", "Pivot always visible", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetPivotAlwaysOn->setStatusTip(QApplication::translate("MainWindow", "Pivot always visible", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetPivotRotationOnly->setText(QApplication::translate("MainWindow", "Rotation only", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetPivotRotationOnly->setToolTip(QApplication::translate("MainWindow", "Pivot visible when rotating", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetPivotRotationOnly->setStatusTip(QApplication::translate("MainWindow", "Pivot visible when rotating", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetPivotOff->setText(QApplication::translate("MainWindow", "Never visible", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetPivotOff->setToolTip(QApplication::translate("MainWindow", "Pivot never visible", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetPivotOff->setStatusTip(QApplication::translate("MainWindow", "Pivot never visible", nullptr));
#endif // QT_NO_STATUSTIP
        actionSetViewIso1->setText(QApplication::translate("MainWindow", "Iso 1", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewIso1->setToolTip(QApplication::translate("MainWindow", "Set view to 'front' isometric", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewIso1->setStatusTip(QApplication::translate("MainWindow", "Set view to 'front' isometric", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewIso1->setShortcut(QApplication::translate("MainWindow", "7", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetViewIso2->setText(QApplication::translate("MainWindow", "Iso 2", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetViewIso2->setToolTip(QApplication::translate("MainWindow", "Set view to 'back' isometric", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSetViewIso2->setStatusTip(QApplication::translate("MainWindow", "Set view to 'back' isometric", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSetViewIso2->setShortcut(QApplication::translate("MainWindow", "9", nullptr));
#endif // QT_NO_SHORTCUT
        actionConvertTextureToColor->setText(QApplication::translate("MainWindow", "Convert texture/material to RGB", nullptr));
        actionOpenColorScalesManager->setText(QApplication::translate("MainWindow", "Color Scales Manager", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpenColorScalesManager->setToolTip(QApplication::translate("MainWindow", "Open Color Scales Manager dialog", nullptr));
#endif // QT_NO_TOOLTIP
        actionCrossSection->setText(QApplication::translate("MainWindow", "Cross Section", nullptr));
#ifndef QT_NO_STATUSTIP
        actionCrossSection->setStatusTip(QApplication::translate("MainWindow", "Cross Section", nullptr));
#endif // QT_NO_STATUSTIP
        actionEditGlobalShiftAndScale->setText(QApplication::translate("MainWindow", "Edit global shift and scale", nullptr));
        actionScalarFieldFromColor->setText(QApplication::translate("MainWindow", "Convert to Scalar field", nullptr));
        actionComputeKdTree->setText(QApplication::translate("MainWindow", "Compute Kd-tree", nullptr));
        actionTest->setText(QApplication::translate("MainWindow", "test", nullptr));
        actionAddIdField->setText(QApplication::translate("MainWindow", "Add point indexes as SF", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAddIdField->setToolTip(QApplication::translate("MainWindow", "Adds a scalar field with ordered integers for each point in the cloud", nullptr));
#endif // QT_NO_TOOLTIP
        actionFitFacet->setText(QApplication::translate("MainWindow", "2D polygon (facet)", nullptr));
        actionAdjustZoom->setText(QApplication::translate("MainWindow", "Adjust zoom", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdjustZoom->setToolTip(QApplication::translate("MainWindow", "Adjusts zoom with a given pixel/unit ratio (orthographic projection only)", nullptr));
#endif // QT_NO_TOOLTIP
        actionSetSFAsCoord->setText(QApplication::translate("MainWindow", "Set SF as coordinate(s)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetSFAsCoord->setToolTip(QApplication::translate("MainWindow", "Set SF as coordinate(s) (X, Y or Z)", nullptr));
#endif // QT_NO_TOOLTIP
        actionCloseAll->setText(QApplication::translate("MainWindow", "Close all", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCloseAll->setToolTip(QApplication::translate("MainWindow", "Remove all entities currently loaded in the DB tree", nullptr));
#endif // QT_NO_TOOLTIP
        actionEditGlobalScale->setText(QApplication::translate("MainWindow", "Edit global scale", nullptr));
        actionViewFromSensor->setText(QApplication::translate("MainWindow", "View from sensor", nullptr));
        actionFindBiggestInnerRectangle->setText(QApplication::translate("MainWindow", "Find biggest inner rectangle (2D)", nullptr));
        actionCreateGBLSensor->setText(QApplication::translate("MainWindow", "Create", nullptr));
        actionCreateCameraSensor->setText(QApplication::translate("MainWindow", "Create", nullptr));
        actionCheckPointsInsideFrustum->setText(QApplication::translate("MainWindow", "Compute points visibility (with octree)", nullptr));
        actionProjectUncertainty->setText(QApplication::translate("MainWindow", "Project Uncertainty", nullptr));
        actionOrientNormalsMST->setText(QApplication::translate("MainWindow", "With Minimum Spanning Tree", nullptr));
        actionOrientNormalsFM->setText(QApplication::translate("MainWindow", "With Fast Marching", nullptr));
        actionCNETest->setText(QApplication::translate("MainWindow", "CNE test", nullptr));
        actionCNETest->setIconText(QApplication::translate("MainWindow", "Cylindrical Neighbourhood Extraction test", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCNETest->setToolTip(QApplication::translate("MainWindow", "Cylindrical Neighbourhood Extraction test", nullptr));
#endif // QT_NO_TOOLTIP
        actionApproximateDensity->setText(QApplication::translate("MainWindow", "Approximate (dist. to nearest neighbor)", nullptr));
        actionComputeDensity->setText(QApplication::translate("MainWindow", "Density", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeDensity->setToolTip(QApplication::translate("MainWindow", "Compute density", nullptr));
#endif // QT_NO_TOOLTIP
        actionRemoveDuplicatePoints->setText(QApplication::translate("MainWindow", "Remove duplicate points", nullptr));
        actionCrop->setText(QApplication::translate("MainWindow", "Crop", nullptr));
        actionConvertNormalToDipDir->setText(QApplication::translate("MainWindow", "Dip/Dip direction SFs", nullptr));
        actionExportCloudInfo->setText(QApplication::translate("MainWindow", "Export cloud info", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExportCloudInfo->setToolTip(QApplication::translate("MainWindow", "Export cloud info to a CSV file (name, size, barycenter, scalar fields info, etc.)", nullptr));
#endif // QT_NO_TOOLTIP
        actionInterpolateColors->setText(QApplication::translate("MainWindow", "Interpolate from another entity", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInterpolateColors->setToolTip(QApplication::translate("MainWindow", "Interpolate colors from another entity (cloud or mesh) - color is taken from the nearest neighbor", nullptr));
#endif // QT_NO_TOOLTIP
        actionDistanceToBestFitQuadric3D->setText(QApplication::translate("MainWindow", "Distance map to best-fit 3D quadric", nullptr));
        actionChangeColorLevels->setText(QApplication::translate("MainWindow", "Levels", nullptr));
        actionResetGUIElementsPos->setText(QApplication::translate("MainWindow", "Reset all GUI element positions", nullptr));
#ifndef QT_NO_TOOLTIP
        actionResetGUIElementsPos->setToolTip(QApplication::translate("MainWindow", "Reset all GUI element positions (after restart)", nullptr));
#endif // QT_NO_TOOLTIP
        actionConvertToRandomRGB->setText(QApplication::translate("MainWindow", "Convert to random RGB", nullptr));
        actionNoiseFilter->setText(QApplication::translate("MainWindow", "Noise filter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNoiseFilter->setToolTip(QApplication::translate("MainWindow", "Noise filter (remove the points far from the - approximate - local surface)", nullptr));
#endif // QT_NO_TOOLTIP
        actionComputeStatParams2->setText(QApplication::translate("MainWindow", "Compute stat. params (active SF)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeStatParams2->setToolTip(QApplication::translate("MainWindow", "Fits a statistical model on the active scalar field", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionComputeStatParams2->setStatusTip(QApplication::translate("MainWindow", "Fits a statistical model on the active scalar field", nullptr));
#endif // QT_NO_STATUSTIP
        actionMeasureMeshVolume->setText(QApplication::translate("MainWindow", "Measure volume", nullptr));
        actionFlagMeshVertices->setText(QApplication::translate("MainWindow", "Flag vertices by type", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFlagMeshVertices->setToolTip(QApplication::translate("MainWindow", "Flag vertices by type: normal (0), border (1), non-manifold (2)", nullptr));
#endif // QT_NO_TOOLTIP
        actionToggleActivation->setText(QApplication::translate("MainWindow", "Activation (not recursive)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleActivation->setToolTip(QApplication::translate("MainWindow", "Enable/disable selected entities (not recursive)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionToggleActivation->setShortcut(QApplication::translate("MainWindow", "A", nullptr));
#endif // QT_NO_SHORTCUT
        actionLockRotationAxis->setText(QApplication::translate("MainWindow", "Lock rotation about an axis", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLockRotationAxis->setToolTip(QApplication::translate("MainWindow", "Lock 3D camera rotation about an axis", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionLockRotationAxis->setShortcut(QApplication::translate("MainWindow", "L", nullptr));
#endif // QT_NO_SHORTCUT
        actionCreateCloudFromEntCenters->setText(QApplication::translate("MainWindow", "Create cloud from selected entities centers", nullptr));
        actionComputeBestICPRmsMatrix->setText(QApplication::translate("MainWindow", "Compute best registration RMS matrix", nullptr));
#ifndef QT_NO_TOOLTIP
        actionComputeBestICPRmsMatrix->setToolTip(QApplication::translate("MainWindow", "Computes the best registration between all couples among multiple entities and save the resulting RMS in a matrix (CSV) file", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnterBubbleViewMode->setText(QApplication::translate("MainWindow", "Enter bubble-view mode", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEnterBubbleViewMode->setShortcut(QApplication::translate("MainWindow", "B", nullptr));
#endif // QT_NO_SHORTCUT
        actionExtractSections->setText(QApplication::translate("MainWindow", "Extract sections / Unfold", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExtractSections->setToolTip(QApplication::translate("MainWindow", "Extract cloud sections along polylines or unfold a cloud along a polyline", nullptr));
#endif // QT_NO_TOOLTIP
        actionConvertPolylinesToMesh->setText(QApplication::translate("MainWindow", "Contour plot (polylines) to mesh", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConvertPolylinesToMesh->setToolTip(QApplication::translate("MainWindow", "Contour plot (set of polylines) to a 2.5D mesh", nullptr));
#endif // QT_NO_TOOLTIP
        actionLevel->setText(QApplication::translate("MainWindow", "Level", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLevel->setToolTip(QApplication::translate("MainWindow", "Pick three points to make a cloud or mesh 'level'", nullptr));
#endif // QT_NO_TOOLTIP
        actionFitSphere->setText(QApplication::translate("MainWindow", "Sphere", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFitSphere->setToolTip(QApplication::translate("MainWindow", "Fits a sphere on the selected cloud", nullptr));
#endif // QT_NO_TOOLTIP
        actionMatchScales->setText(QApplication::translate("MainWindow", "Match scales", nullptr));
        actionZoomIn->setText(QApplication::translate("MainWindow", "Zoom in", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomIn->setToolTip(QApplication::translate("MainWindow", "Zoom in (current 3D view)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "+", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoomOut->setText(QApplication::translate("MainWindow", "Zoom out", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomOut->setToolTip(QApplication::translate("MainWindow", "Zoom out (current 3D view)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "=", nullptr));
#endif // QT_NO_SHORTCUT
        actionDistanceMap->setText(QApplication::translate("MainWindow", "Distance map", nullptr));
        actionSORFilter->setText(QApplication::translate("MainWindow", "SOR filter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSORFilter->setToolTip(QApplication::translate("MainWindow", "Statistical Outlier Filter (remove the points far from their neighbors)", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnableStereo->setText(QApplication::translate("MainWindow", "actionEnableStereo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEnableStereo->setToolTip(QApplication::translate("MainWindow", "Enable stereo mode (with red-blue or red-cyan glasses)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionEnableStereo->setShortcut(QApplication::translate("MainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        actionComputePointsVisibility->setText(QApplication::translate("MainWindow", "Compute points visibility (with depth buffer)", nullptr));
        actionCompute2HalfDimVolume->setText(QApplication::translate("MainWindow", "Compute 2.5D volume", nullptr));
        actionExclusiveFullScreen->setText(QApplication::translate("MainWindow", "Full screen (3D view)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExclusiveFullScreen->setToolTip(QApplication::translate("MainWindow", "Exclusive full screen (3D view)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionExclusiveFullScreen->setShortcut(QApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        actionEnableVisualDebugTraces->setText(QApplication::translate("MainWindow", "Enable Visual Debug Traces", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEnableVisualDebugTraces->setToolTip(QApplication::translate("MainWindow", "Enables visual debug traces (active 3D view)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionEnableVisualDebugTraces->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionRGBToGreyScale->setText(QApplication::translate("MainWindow", "Convert to grey scale", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRGBToGreyScale->setToolTip(QApplication::translate("MainWindow", "Convert RGB colors to grey scale colors", nullptr));
#endif // QT_NO_TOOLTIP
        actionTracePolyline->setText(QApplication::translate("MainWindow", "Trace Polyline", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTracePolyline->setToolTip(QApplication::translate("MainWindow", "Trace a polyline by point picking", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionTracePolyline->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionEnableQtWarnings->setText(QApplication::translate("MainWindow", "Enable Qt warnings in Console", nullptr));
        actionGlobalShiftSettings->setText(QApplication::translate("MainWindow", "Global Shift settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionGlobalShiftSettings->setToolTip(QApplication::translate("MainWindow", "Set Global Shift & Scale mechanism parameters", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnableCameraLink->setText(QApplication::translate("MainWindow", "Camera link", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEnableCameraLink->setToolTip(QApplication::translate("MainWindow", "Link the cameras of all 3D views\n"
"(so that they all move in the same way and at the same time)", nullptr));
#endif // QT_NO_TOOLTIP
        actionShowWaveDialog->setText(QApplication::translate("MainWindow", "2D Waveform viewer", nullptr));
        actionCreatePlane->setText(QApplication::translate("MainWindow", "Create", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCreatePlane->setToolTip(QApplication::translate("MainWindow", "Create a plane", nullptr));
#endif // QT_NO_TOOLTIP
        actionEditPlane->setText(QApplication::translate("MainWindow", "Edit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEditPlane->setToolTip(QApplication::translate("MainWindow", "Edit the plane parameters", nullptr));
#endif // QT_NO_TOOLTIP
        actionCreateSurfaceBetweenTwoPolylines->setText(QApplication::translate("MainWindow", "Create surface between two polylines", nullptr));
        actionMeshTwoPolylines->setText(QApplication::translate("MainWindow", "Surface between 2 polylines", nullptr));
        actionFitPlaneProxy->setText(QApplication::translate("MainWindow", "Fit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFitPlaneProxy->setToolTip(QApplication::translate("MainWindow", "Fit a plane on a set of point", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnhanceRGBWithIntensities->setText(QApplication::translate("MainWindow", "Enhance with intensities", nullptr));
        actionMeshScanGrids->setText(QApplication::translate("MainWindow", "Mesh scan grids", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMeshScanGrids->setToolTip(QApplication::translate("MainWindow", "Mesh scan grids (structured point clouds)", nullptr));
#endif // QT_NO_TOOLTIP
        actionAutoPickRotationCenter->setText(QApplication::translate("MainWindow", "Auto-pick rotation center", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAutoPickRotationCenter->setToolTip(QApplication::translate("MainWindow", "Auto-pick rotation center (rotation is always placed at the middle of the screen if possible)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAutoPickRotationCenter->setShortcut(QApplication::translate("MainWindow", "Shift+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowCursor3DCoordinates->setText(QApplication::translate("MainWindow", "Show cursor coordinates", nullptr));
#ifndef QT_NO_TOOLTIP
        actionShowCursor3DCoordinates->setToolTip(QApplication::translate("MainWindow", "Show cursor coordinates (2D and 3D if possible)", nullptr));
#endif // QT_NO_TOOLTIP
        actionDeleteScanGrid->setText(QApplication::translate("MainWindow", "Delete scan grids", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDeleteScanGrid->setToolTip(QApplication::translate("MainWindow", "Delete the underlying scan grids", nullptr));
#endif // QT_NO_TOOLTIP
        actionCompressFWFData->setText(QApplication::translate("MainWindow", "Compress FWF data", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCompressFWFData->setToolTip(QApplication::translate("MainWindow", "Compress the associated FWF data (maybe interesting after interactive segmentation for instance)", nullptr));
#endif // QT_NO_TOOLTIP
        actionInterpolateSFs->setText(QApplication::translate("MainWindow", "Interpolate from another entity", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInterpolateSFs->setToolTip(QApplication::translate("MainWindow", "Interpolate scalar-field(s) from another cloud or mesh", nullptr));
#endif // QT_NO_TOOLTIP
        actionExportPlaneInfo->setText(QApplication::translate("MainWindow", "Export plane info", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExportPlaneInfo->setToolTip(QApplication::translate("MainWindow", "Export plane info to a CSV file (name, width, height, center, normal, dip and dip direction, etc.)", nullptr));
#endif // QT_NO_TOOLTIP
        actionLock_rotation_about_arbitrary_axis->setText(QApplication::translate("MainWindow", "Lock rotation about arbitrary axis", nullptr));
        actionSamplePointsOnPolyline->setText(QApplication::translate("MainWindow", "Sample points", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuDisplay->setTitle(QApplication::translate("MainWindow", "&Display", nullptr));
        menuToolbars->setTitle(QApplication::translate("MainWindow", "Toolbars", nullptr));
        menuLights->setTitle(QApplication::translate("MainWindow", "Lights", nullptr));
        menuActiveScalarField->setTitle(QApplication::translate("MainWindow", "Active scalar field", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuScalarFields->setTitle(QApplication::translate("MainWindow", "Scalar fields", nullptr));
        menuColors->setTitle(QApplication::translate("MainWindow", "Colors", nullptr));
        menuNormals->setTitle(QApplication::translate("MainWindow", "Normals", nullptr));
        menuOrientNormals->setTitle(QApplication::translate("MainWindow", "Orient normals", nullptr));
        menuConvert_to->setTitle(QApplication::translate("MainWindow", "Convert to", nullptr));
        menuOctree->setTitle(QApplication::translate("MainWindow", "Octree", nullptr));
        menuMesh->setTitle(QApplication::translate("MainWindow", "Mesh", nullptr));
        menuMeshScalarField->setTitle(QApplication::translate("MainWindow", "Scalar Field", nullptr));
        menuSensors->setTitle(QApplication::translate("MainWindow", "Sensors", nullptr));
#ifndef QT_NO_TOOLTIP
        menuGroundBasedLidar->setToolTip(QApplication::translate("MainWindow", "Terrestrial Laser Sensor = Ground Based Lidar", nullptr));
#endif // QT_NO_TOOLTIP
        menuGroundBasedLidar->setTitle(QApplication::translate("MainWindow", "TLS/GBL", nullptr));
        menuCameraSensor->setTitle(QApplication::translate("MainWindow", "Camera", nullptr));
        menuToggle->setTitle(QApplication::translate("MainWindow", "Toggle (recursive)", nullptr));
        menuWaveform->setTitle(QApplication::translate("MainWindow", "Waveform", nullptr));
        menuPlane->setTitle(QApplication::translate("MainWindow", "Plane", nullptr));
        menuGrid->setTitle(QApplication::translate("MainWindow", "Grid", nullptr));
        menuPolyline->setTitle(QApplication::translate("MainWindow", "Polyline", nullptr));
        menu3DViews->setTitle(QApplication::translate("MainWindow", "3D &Views", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuSegmentation->setTitle(QApplication::translate("MainWindow", "Segmentation", nullptr));
        menuProjection->setTitle(QApplication::translate("MainWindow", "Projection", nullptr));
        menuStatistics->setTitle(QApplication::translate("MainWindow", "Statistics", nullptr));
        menuDistances->setTitle(QApplication::translate("MainWindow", "Distances", nullptr));
        menuRegistration->setTitle(QApplication::translate("MainWindow", "Registration", nullptr));
        menuOther->setTitle(QApplication::translate("MainWindow", "Other", nullptr));
        menuSandBox->setTitle(QApplication::translate("MainWindow", "Sand box (research)", nullptr));
        menuFit->setTitle(QApplication::translate("MainWindow", "Fit", nullptr));
        menuClean->setTitle(QApplication::translate("MainWindow", "Clean", nullptr));
        menuVolume->setTitle(QApplication::translate("MainWindow", "Volume", nullptr));
        menuBatchExport->setTitle(QApplication::translate("MainWindow", "Batch export", nullptr));
        DockableDBTree->setWindowTitle(QApplication::translate("MainWindow", "DB Tree", nullptr));
        toolBarView->setWindowTitle(QApplication::translate("MainWindow", "Viewing tools", nullptr));
#ifndef QT_NO_TOOLTIP
        toolBarView->setToolTip(QApplication::translate("MainWindow", "Viewing tools", nullptr));
#endif // QT_NO_TOOLTIP
        DockableConsole->setWindowTitle(QApplication::translate("MainWindow", "Console", nullptr));
        toolBarMainTools->setWindowTitle(QApplication::translate("MainWindow", "Main tools", nullptr));
#ifndef QT_NO_TOOLTIP
        toolBarMainTools->setToolTip(QApplication::translate("MainWindow", "Main tools", nullptr));
#endif // QT_NO_TOOLTIP
        toolBarSFTools->setWindowTitle(QApplication::translate("MainWindow", "Scalar field tools", nullptr));
#ifndef QT_NO_TOOLTIP
        toolBarSFTools->setToolTip(QApplication::translate("MainWindow", "Scalar field tools", nullptr));
#endif // QT_NO_TOOLTIP
        DockableProperties->setWindowTitle(QApplication::translate("MainWindow", "Properties", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
