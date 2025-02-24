module org.example.sortingmenu {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;

    opens org.example.sortingmenu to javafx.fxml;
    exports org.example.sortingmenu;
}