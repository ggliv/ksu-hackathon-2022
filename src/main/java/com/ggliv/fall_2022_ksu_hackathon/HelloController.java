package com.ggliv.fall_2022_ksu_hackathon;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class HelloController {

  @FXML
  private Label welcomeText;

  @FXML
  protected void onHelloButtonClick() {
    welcomeText.setText("Welcome to JavaFX Application!");
  }
}