module com.ggliv.fall_2022_ksu_hackathon {
  requires javafx.controls;
  requires javafx.fxml;

  requires org.controlsfx.controls;
  requires com.dlsc.formsfx;
  requires org.kordamp.ikonli.javafx;
  requires org.kordamp.bootstrapfx.core;

  opens com.ggliv.fall_2022_ksu_hackathon to javafx.fxml;
  exports com.ggliv.fall_2022_ksu_hackathon;
}