package org.example.sortingmenu;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

import java.io.File;
import java.io.IOException;

public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick() {
//        File folder = new File("./../cmake-build-debug");
//
//        // Sprawdzanie, czy folder istnieje i jest katalogiem
//        if (folder.exists() && folder.isDirectory()) {
//            // Pobieranie listy plików w folderze
//            String[] files = folder.list();
//
//            if (files != null) {
//                // Wypisywanie nazw plików
//                for (String file : files) {
//                    System.out.println(file);
//                }
//            } else {
//                System.out.println("Folder jest pusty lub nie ma uprawnień do odczytu.");
//            }
//        } else {
//            System.out.println("Podana ścieżka nie jest katalogiem lub nie istnieje.");
//        }

        ProcessBuilder processBuilder = new ProcessBuilder("./../cmake-build-debug/Sorting.exe");
        try {
            Process process = processBuilder.start();
            process.waitFor();
            System.out.println("Program C++ zakończył się sukcesem.");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            System.out.println("Błąd podczas uruchamiania programu.");
        }
    }
}