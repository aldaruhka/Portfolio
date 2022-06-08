package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;

import java.io.*;

import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.VBox;

public class Controller {

    public Button newNote;
    public VBox vbox;
    public Button delNote;
    public TextArea noteWindow;
    public Button saveButton;
    private int countOfNotes;
    private Button openedFileRightNow;

    private Button createNoteButton(String textInButton, String id) {
        Button newButton = new Button();
        //maxHeight="60.0" maxWidth="300.0" minHeight="60.0" minWidth="300.0" mnemonicParsing="false" prefHeight="60.0" prefWidth="300.0"
        newButton.setMaxHeight(60);
        newButton.setMaxWidth(300);
        newButton.setMinHeight(60);
        newButton.setMinWidth(300);
        newButton.setId(id);
        newButton.setText(textInButton);
        newButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                try {
                    noteWindow.clear();
                    FileReader fileReader = new FileReader(newButton.getId());
                    char[] readedText = new char[40];
                    while (fileReader.read(readedText, 0, 40) > 0) {
                        String tmp = new String(readedText);
                        noteWindow.appendText(tmp);
                    }
                    fileReader.close();
                    openedFileRightNow = newButton;
                    noteWindow.setEditable(true);
                    System.out.println("now open: " + openedFileRightNow.getId());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        return newButton;
    }

    private String[] takeNotesNames() {
        File folder = new File(".");
        String[] notesNames = folder.list(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                return name.startsWith("note");
            }
        });
        countOfNotes = 1 + Integer.parseInt(notesNames[notesNames.length - 1].substring(4, notesNames[notesNames.length - 1].length() - 4));
        return notesNames;
    }

    public void newNoteClick(javafx.event.ActionEvent actionEvent) {
        File fileForNewNote = new File("note" + countOfNotes + ".txt");
        try {
            fileForNewNote.createNewFile();
            Button newButton = createNoteButton("Empty note", fileForNewNote.getName());
            vbox.getChildren().add(newButton);
            System.out.println(newButton.getId() + "\n" + fileForNewNote.getName());
        } catch (IOException e) {
            e.printStackTrace();
        }
        countOfNotes++;
    }

    @FXML public void initialize() {
        String[] notesNames = takeNotesNames();
        for(int i = 0; i < notesNames.length; i++) {
            try {
                FileReader fileReader = new FileReader(notesNames[i]);
                char[] readedText = new char[40];
                fileReader.read(readedText, 0, 40);
                fileReader.close();
                String textInButton = new String(readedText);
                Button newButton = createNoteButton(textInButton + "...", notesNames[i]);
                vbox.getChildren().add(newButton);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        noteWindow.setEditable(false);
    }

    public void delNoteClick(ActionEvent actionEvent) {
        if (openedFileRightNow != null) {
            noteWindow.clear();
            File file = new File(openedFileRightNow.getId());
            vbox.getChildren().remove(openedFileRightNow);
            openedFileRightNow = null;
            noteWindow.setEditable(false);
            System.out.println(file.getName() + " : " + file.delete());
        }
        else
            noteWindow.setText("Выберите заметку для удаления, затем нажмите \"-\"");
    }

    public void saveNoteText(ActionEvent inputMethodEvent) {
        FileWriter file = null;
        try {
            file = new FileWriter(openedFileRightNow.getId());
            //System.out.println(noteWindow.getText());
            file.write(noteWindow.getText());
            file.close();
            int length = noteWindow.getText().length();
            openedFileRightNow.setText(noteWindow.getText().substring(0, length > 40 ? 40 : length) + "...");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
