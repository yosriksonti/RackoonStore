# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dw_buttons.ui'
#
# Created: Fri Nov  9 18:42:55 2018
#      by: pyside2-uic 2.0.0 running on PySide2 5.6.0~a1
#
# WARNING! All changes made in this file will be lost!

from PySide2 import QtCore, QtGui, QtWidgets

class Ui_DockWidget(object):
    def setupUi(self, DockWidget):
        DockWidget.setObjectName("DockWidget")
        DockWidget.resize(527, 460)
        self.dockWidgetContents = QtWidgets.QWidget()
        self.dockWidgetContents.setObjectName("dockWidgetContents")
        self.gridLayout = QtWidgets.QGridLayout(self.dockWidgetContents)
        self.gridLayout.setObjectName("gridLayout")
        self.label_72 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_72.setFont(font)
        self.label_72.setObjectName("label_72")
        self.gridLayout.addWidget(self.label_72, 0, 1, 1, 1)
        self.label_73 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_73.setFont(font)
        self.label_73.setObjectName("label_73")
        self.gridLayout.addWidget(self.label_73, 0, 2, 1, 1)
        self.label_26 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_26.setMinimumSize(QtCore.QSize(0, 0))
        self.label_26.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_26.setFont(font)
        self.label_26.setObjectName("label_26")
        self.gridLayout.addWidget(self.label_26, 1, 0, 1, 1)
        self.pushButton = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButton.setMinimumSize(QtCore.QSize(0, 0))
        self.pushButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 1, 1, 1, 1)
        self.pushButtonDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonDis.setEnabled(False)
        self.pushButtonDis.setMinimumSize(QtCore.QSize(0, 0))
        self.pushButtonDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButtonDis.setDefault(False)
        self.pushButtonDis.setObjectName("pushButtonDis")
        self.gridLayout.addWidget(self.pushButtonDis, 1, 2, 1, 1)
        self.label_74 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_74.setFont(font)
        self.label_74.setObjectName("label_74")
        self.gridLayout.addWidget(self.label_74, 2, 0, 1, 1)
        self.pushButtonChecked = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonChecked.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButtonChecked.setCheckable(True)
        self.pushButtonChecked.setChecked(True)
        self.pushButtonChecked.setObjectName("pushButtonChecked")
        self.gridLayout.addWidget(self.pushButtonChecked, 2, 1, 1, 1)
        self.pushButtonCheckedDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonCheckedDis.setEnabled(False)
        self.pushButtonCheckedDis.setCheckable(True)
        self.pushButtonCheckedDis.setChecked(True)
        self.pushButtonCheckedDis.setObjectName("pushButtonCheckedDis")
        self.gridLayout.addWidget(self.pushButtonCheckedDis, 2, 2, 1, 1)
        self.label_76 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_76.setFont(font)
        self.label_76.setObjectName("label_76")
        self.gridLayout.addWidget(self.label_76, 3, 0, 1, 1)
        self.pushButtonUnchecked = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonUnchecked.setCheckable(True)
        self.pushButtonUnchecked.setObjectName("pushButtonUnchecked")
        self.gridLayout.addWidget(self.pushButtonUnchecked, 3, 1, 1, 1)
        self.pushButtonUncheckedDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonUncheckedDis.setEnabled(False)
        self.pushButtonUncheckedDis.setCheckable(True)
        self.pushButtonUncheckedDis.setObjectName("pushButtonUncheckedDis")
        self.gridLayout.addWidget(self.pushButtonUncheckedDis, 3, 2, 1, 1)
        self.label_33 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_33.setMinimumSize(QtCore.QSize(0, 0))
        self.label_33.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_33.setFont(font)
        self.label_33.setObjectName("label_33")
        self.gridLayout.addWidget(self.label_33, 4, 0, 1, 1)
        self.toolButton = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButton.setMinimumSize(QtCore.QSize(0, 0))
        self.toolButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.toolButton.setObjectName("toolButton")
        self.gridLayout.addWidget(self.toolButton, 4, 1, 1, 1)
        self.toolButtonDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDis.setEnabled(False)
        self.toolButtonDis.setMinimumSize(QtCore.QSize(0, 0))
        self.toolButtonDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.toolButtonDis.setObjectName("toolButtonDis")
        self.gridLayout.addWidget(self.toolButtonDis, 4, 2, 1, 1)
        self.label_75 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_75.setFont(font)
        self.label_75.setObjectName("label_75")
        self.gridLayout.addWidget(self.label_75, 5, 0, 1, 1)
        self.radioButtonChecked = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonChecked.setChecked(True)
        self.radioButtonChecked.setAutoExclusive(False)
        self.radioButtonChecked.setObjectName("radioButtonChecked")
        self.gridLayout.addWidget(self.radioButtonChecked, 5, 1, 1, 1)
        self.radioButtonCheckedDis = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonCheckedDis.setEnabled(False)
        self.radioButtonCheckedDis.setChecked(True)
        self.radioButtonCheckedDis.setAutoExclusive(False)
        self.radioButtonCheckedDis.setObjectName("radioButtonCheckedDis")
        self.gridLayout.addWidget(self.radioButtonCheckedDis, 5, 2, 1, 1)
        self.label_29 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_29.setMinimumSize(QtCore.QSize(0, 0))
        self.label_29.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_29.setFont(font)
        self.label_29.setObjectName("label_29")
        self.gridLayout.addWidget(self.label_29, 6, 0, 1, 1)
        self.radioButtonUnchecked = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonUnchecked.setMinimumSize(QtCore.QSize(0, 0))
        self.radioButtonUnchecked.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.radioButtonUnchecked.setAutoExclusive(False)
        self.radioButtonUnchecked.setObjectName("radioButtonUnchecked")
        self.gridLayout.addWidget(self.radioButtonUnchecked, 6, 1, 1, 1)
        self.radioButtonUncheckedDis = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonUncheckedDis.setEnabled(False)
        self.radioButtonUncheckedDis.setMinimumSize(QtCore.QSize(0, 0))
        self.radioButtonUncheckedDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.radioButtonUncheckedDis.setChecked(False)
        self.radioButtonUncheckedDis.setAutoExclusive(False)
        self.radioButtonUncheckedDis.setObjectName("radioButtonUncheckedDis")
        self.gridLayout.addWidget(self.radioButtonUncheckedDis, 6, 2, 1, 1)
        self.label_53 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_53.setFont(font)
        self.label_53.setObjectName("label_53")
        self.gridLayout.addWidget(self.label_53, 7, 0, 1, 1)
        self.checkBoxChecked = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxChecked.setChecked(True)
        self.checkBoxChecked.setObjectName("checkBoxChecked")
        self.gridLayout.addWidget(self.checkBoxChecked, 7, 1, 1, 1)
        self.checkBoxCheckedDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxCheckedDis.setEnabled(False)
        self.checkBoxCheckedDis.setChecked(True)
        self.checkBoxCheckedDis.setObjectName("checkBoxCheckedDis")
        self.gridLayout.addWidget(self.checkBoxCheckedDis, 7, 2, 1, 1)
        self.label_30 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_30.setMinimumSize(QtCore.QSize(0, 0))
        self.label_30.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_30.setFont(font)
        self.label_30.setObjectName("label_30")
        self.gridLayout.addWidget(self.label_30, 8, 0, 1, 1)
        self.checkBoxEnabled = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxEnabled.setMinimumSize(QtCore.QSize(0, 0))
        self.checkBoxEnabled.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.checkBoxEnabled.setTristate(False)
        self.checkBoxEnabled.setObjectName("checkBoxEnabled")
        self.gridLayout.addWidget(self.checkBoxEnabled, 8, 1, 1, 1)
        self.checkBoxUncheckedDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxUncheckedDis.setEnabled(False)
        self.checkBoxUncheckedDis.setMinimumSize(QtCore.QSize(0, 0))
        self.checkBoxUncheckedDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.checkBoxUncheckedDis.setChecked(False)
        self.checkBoxUncheckedDis.setObjectName("checkBoxUncheckedDis")
        self.gridLayout.addWidget(self.checkBoxUncheckedDis, 8, 2, 1, 1)
        self.label_31 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_31.setMinimumSize(QtCore.QSize(0, 0))
        self.label_31.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_31.setFont(font)
        self.label_31.setObjectName("label_31")
        self.gridLayout.addWidget(self.label_31, 10, 0, 1, 1)
        self.commandLinkButton = QtWidgets.QCommandLinkButton(self.dockWidgetContents)
        self.commandLinkButton.setMinimumSize(QtCore.QSize(0, 0))
        self.commandLinkButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.commandLinkButton.setObjectName("commandLinkButton")
        self.gridLayout.addWidget(self.commandLinkButton, 10, 1, 1, 1)
        self.commandLinkButtonDIs = QtWidgets.QCommandLinkButton(self.dockWidgetContents)
        self.commandLinkButtonDIs.setEnabled(False)
        self.commandLinkButtonDIs.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.commandLinkButtonDIs.setObjectName("commandLinkButtonDIs")
        self.gridLayout.addWidget(self.commandLinkButtonDIs, 10, 2, 1, 1)
        self.label_32 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_32.setMinimumSize(QtCore.QSize(0, 0))
        self.label_32.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.label_32.setFont(font)
        self.label_32.setObjectName("label_32")
        self.gridLayout.addWidget(self.label_32, 11, 0, 1, 1)
        self.buttonBox = QtWidgets.QDialogButtonBox(self.dockWidgetContents)
        self.buttonBox.setMinimumSize(QtCore.QSize(0, 0))
        self.buttonBox.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.gridLayout.addWidget(self.buttonBox, 11, 1, 1, 1)
        self.buttonBoxDis = QtWidgets.QDialogButtonBox(self.dockWidgetContents)
        self.buttonBoxDis.setEnabled(False)
        self.buttonBoxDis.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBoxDis.setObjectName("buttonBoxDis")
        self.gridLayout.addWidget(self.buttonBoxDis, 11, 2, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(20, 4, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 12, 0, 1, 1)
        self.label_36 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_36.setAlignment(QtCore.Qt.AlignCenter)
        self.label_36.setObjectName("label_36")
        self.gridLayout.addWidget(self.label_36, 13, 0, 1, 3)
        self.label = QtWidgets.QLabel(self.dockWidgetContents)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 9, 0, 1, 1)
        self.checkBoxTristate = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxTristate.setChecked(False)
        self.checkBoxTristate.setTristate(True)
        self.checkBoxTristate.setObjectName("checkBoxTristate")
        self.gridLayout.addWidget(self.checkBoxTristate, 9, 1, 1, 1)
        self.checkBoxTristateDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxTristateDis.setEnabled(False)
        self.checkBoxTristateDis.setChecked(False)
        self.checkBoxTristateDis.setTristate(True)
        self.checkBoxTristateDis.setObjectName("checkBoxTristateDis")
        self.gridLayout.addWidget(self.checkBoxTristateDis, 9, 2, 1, 1)
        DockWidget.setWidget(self.dockWidgetContents)

        self.retranslateUi(DockWidget)
        QtCore.QObject.connect(self.radioButtonChecked, QtCore.SIGNAL("clicked(bool)"), self.radioButtonCheckedDis.setChecked)
        QtCore.QObject.connect(self.radioButtonUnchecked, QtCore.SIGNAL("clicked(bool)"), self.radioButtonUncheckedDis.setChecked)
        QtCore.QObject.connect(self.checkBoxChecked, QtCore.SIGNAL("clicked(bool)"), self.checkBoxCheckedDis.setChecked)
        QtCore.QObject.connect(self.checkBoxEnabled, QtCore.SIGNAL("clicked(bool)"), self.checkBoxUncheckedDis.setChecked)
        QtCore.QObject.connect(self.checkBoxTristate, QtCore.SIGNAL("clicked(bool)"), self.checkBoxTristateDis.setChecked)
        QtCore.QObject.connect(self.commandLinkButton, QtCore.SIGNAL("clicked(bool)"), self.commandLinkButtonDIs.setChecked)
        QtCore.QObject.connect(self.toolButton, QtCore.SIGNAL("clicked(bool)"), self.toolButtonDis.setChecked)
        QtCore.QObject.connect(self.pushButtonChecked, QtCore.SIGNAL("clicked(bool)"), self.pushButtonCheckedDis.setChecked)
        QtCore.QObject.connect(self.pushButtonUnchecked, QtCore.SIGNAL("clicked(bool)"), self.pushButtonUncheckedDis.setChecked)
        QtCore.QObject.connect(self.pushButton, QtCore.SIGNAL("clicked(bool)"), self.pushButtonDis.click)
        QtCore.QMetaObject.connectSlotsByName(DockWidget)

    def retranslateUi(self, DockWidget):
        DockWidget.setWindowTitle(QtWidgets.QApplication.translate("DockWidget", "Buttons", None, -1))
        self.label_72.setText(QtWidgets.QApplication.translate("DockWidget", "Enabled", None, -1))
        self.label_73.setText(QtWidgets.QApplication.translate("DockWidget", "Disabled", None, -1))
        self.label_26.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_26.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_26.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_26.setText(QtWidgets.QApplication.translate("DockWidget", "PushButton", None, -1))
        self.pushButton.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.pushButton.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.pushButton.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.pushButton.setText(QtWidgets.QApplication.translate("DockWidget", "OK", None, -1))
        self.pushButtonDis.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.pushButtonDis.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.pushButtonDis.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.pushButtonDis.setText(QtWidgets.QApplication.translate("DockWidget", "OK", None, -1))
        self.label_74.setText(QtWidgets.QApplication.translate("DockWidget", "PushButton", None, -1))
        self.pushButtonChecked.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.pushButtonCheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.label_76.setText(QtWidgets.QApplication.translate("DockWidget", "PushButton", None, -1))
        self.pushButtonUnchecked.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.pushButtonUncheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.label_33.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_33.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_33.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_33.setText(QtWidgets.QApplication.translate("DockWidget", "ToolButton", None, -1))
        self.toolButton.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.toolButton.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.toolButton.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.toolButton.setText(QtWidgets.QApplication.translate("DockWidget", "Tool", None, -1))
        self.toolButtonDis.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.toolButtonDis.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.toolButtonDis.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.toolButtonDis.setText(QtWidgets.QApplication.translate("DockWidget", "Tool", None, -1))
        self.label_75.setText(QtWidgets.QApplication.translate("DockWidget", "RadioButton", None, -1))
        self.radioButtonChecked.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.radioButtonCheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.label_29.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_29.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_29.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_29.setText(QtWidgets.QApplication.translate("DockWidget", "RadioButton", None, -1))
        self.radioButtonUnchecked.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.radioButtonUnchecked.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.radioButtonUnchecked.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.radioButtonUnchecked.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.radioButtonUncheckedDis.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.radioButtonUncheckedDis.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.radioButtonUncheckedDis.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.radioButtonUncheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.label_53.setText(QtWidgets.QApplication.translate("DockWidget", "CheckBox", None, -1))
        self.checkBoxChecked.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.checkBoxCheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Checked", None, -1))
        self.label_30.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_30.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_30.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_30.setText(QtWidgets.QApplication.translate("DockWidget", "CheckBox", None, -1))
        self.checkBoxEnabled.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.checkBoxEnabled.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.checkBoxEnabled.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.checkBoxEnabled.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.checkBoxUncheckedDis.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.checkBoxUncheckedDis.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.checkBoxUncheckedDis.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.checkBoxUncheckedDis.setText(QtWidgets.QApplication.translate("DockWidget", "Unchecked", None, -1))
        self.label_31.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_31.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_31.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_31.setText(QtWidgets.QApplication.translate("DockWidget", "CommandLinkButton", None, -1))
        self.commandLinkButton.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.commandLinkButton.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.commandLinkButton.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.commandLinkButton.setText(QtWidgets.QApplication.translate("DockWidget", "Command", None, -1))
        self.commandLinkButtonDIs.setText(QtWidgets.QApplication.translate("DockWidget", "Command", None, -1))
        self.label_32.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_32.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_32.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_32.setText(QtWidgets.QApplication.translate("DockWidget", "ButtonBox", None, -1))
        self.buttonBox.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.buttonBox.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.buttonBox.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_36.setToolTip(QtWidgets.QApplication.translate("DockWidget", "This is a tool tip", None, -1))
        self.label_36.setStatusTip(QtWidgets.QApplication.translate("DockWidget", "This is a status tip", None, -1))
        self.label_36.setWhatsThis(QtWidgets.QApplication.translate("DockWidget", "This is \"what is this\"", None, -1))
        self.label_36.setText(QtWidgets.QApplication.translate("DockWidget", "Inside DockWidget", None, -1))
        self.label.setText(QtWidgets.QApplication.translate("DockWidget", "CheckBox", None, -1))
        self.checkBoxTristate.setText(QtWidgets.QApplication.translate("DockWidget", "Tristate", None, -1))
        self.checkBoxTristateDis.setText(QtWidgets.QApplication.translate("DockWidget", "Tristate", None, -1))

