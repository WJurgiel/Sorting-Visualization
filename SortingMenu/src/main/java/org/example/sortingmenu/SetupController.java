package org.example.sortingmenu;

import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class SetupController {
    @FXML
    Button installButton;
    @FXML
    TextField destinationFolder;
    @FXML
    ProgressBar progressBar;
    @FXML
    TextArea outputArea;
    @FXML
    private void runInstallation(){
        progressBar.setDisable(false);
        outputArea.setDisable(false);
        installButton.setDisable(true);
        outputArea.appendText("Installation initialized...\n");

        Task<Void> task = new Task<>() {
            @Override
            protected Void call() throws Exception {
                String destination = destinationFolder.getText().trim() + "/";
                ProcessBuilder builder = new ProcessBuilder("./../setup.bat ", destination);
                builder.redirectErrorStream(true);
                Process process = builder.start();
                try(BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                    String line;
                    int totalSteps = 362, step = 0;
                    while ((line = reader.readLine()) != null) {
                        String finalLine = line +"\n";
                        updateMessage(finalLine);
                        updateProgress(++step, totalSteps);
                    }
                }
                process.waitFor();
                updateProgress(1,1);
                return null;
            }
        };
        task.messageProperty().addListener((observable, oldValue, newValue) -> outputArea.appendText(newValue));
        progressBar.progressProperty().bind(task.progressProperty());

        task.setOnSucceeded(_ -> {
            outputArea.appendText("Installation completed\n");
            installButton.setDisable(false);
        });
        new Thread(task).start();
    }
}
