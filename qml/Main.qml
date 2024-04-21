import Felgo
import QtQuick
import qtcpp 1.0

App {
    NavigationStack {
        AppPage {
            title: qsTr("Main Page")

            Image {
                source: "../assets/felgo-logo.png"
                anchors.centerIn: parent
            }


            TaskRunner {
                id: taskRunner
                onTaskCompleted: function(result) {  // 使用函数并显式声明参数
                    myButton.text = result; // 更新按钮文本
                }
            }

            AppButton {
                id: myButton
                text: qsTr("Click Me")
                anchors.centerIn: parent
                onClicked: {
                    taskRunner.runTaskFlow(); // Run task when button is clicked
                }
            }
        }
    }
}
