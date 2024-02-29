import java.io.BufferedReader;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

import static java.nio.file.StandardOpenOption.APPEND;
import static java.nio.file.StandardOpenOption.CREATE;

public class Main {
    static HashMap<String, Translation> dictionary = new HashMap<>();
    public static void main(String[] args) {
        zad1();
        zad2();

    }
    public static void zad2(){
        ArrayList<String> list1 = new ArrayList<>();
        LinkedList<String> list2 = new LinkedList<>();
        StringArrays stringArrays = new StringArrays();
        long start, stop;

        //poczatek
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list1.add(0,o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na początek ArrayList: " + (stop - start));
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list1.add(0,o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na początek LinkedList: " + (stop - start));

        list1.clear();
        list2.clear();

        //koniec
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list1.add(o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na koniec LinkedList: " + (stop - start));
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list2.add(o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na koniec ArrayList: " + (stop - start));

        //srodek
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list1.add(list1.size()/2,o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na środek ArrayList: " + (stop - start));
        start = System.nanoTime();
        for(String o : stringArrays.getT1()){
            list2.add(list2.size()/2,o);
        }
        stop = System.nanoTime();
        System.out.println("Czas dodawania na środek LinkedList: " + (stop - start));

        //wyszukanie wszystkich el. tablicy t2 (pojedynczo)
        start = System.nanoTime();
        for(String o : stringArrays.getT2()){
            list1.contains(o);
        }
        stop = System.nanoTime();
        System.out.println("Czas wyszukiwania wszystkich el. tablicy t2 (pojedynczo) ArrayList: " + (stop - start));
        start = System.nanoTime();
        for(String o : stringArrays.getT2()){
            list2.contains(o);
        }
        stop = System.nanoTime();
        System.out.println("Czas wyszukiwania wszystkich el. tablicy t2 (pojedynczo) LinkedList: " + (stop - start));


        list1.clear();
        list2.clear();

        //dodanie T3
        for(String o : stringArrays.getT3()){
            list1.add(o);
            list2.add(o);
        }
        //wyszukanie wszystkich el. tablicy t3 (pojedynczo)
        start = System.nanoTime();
        for(String o : stringArrays.getT3()){
            list1.contains(o);
        }
        stop = System.nanoTime();
        System.out.println("Czas wyszukiwania wszystkich el. tablicy t3 (pojedynczo) ArrayList: " + (stop - start));
        start = System.nanoTime();
        for(String o : stringArrays.getT3()){
            list2.contains(o);
        }
        stop = System.nanoTime();

        //iteracja po wszystkich el. listy
        start = System.nanoTime();
        for(int i = 0 ; i < list1.size() ; i++){
            list1.get(i);
        }
        stop = System.nanoTime();
        System.out.println("Czas iteracji po wszystkich el. listy ArrayList: " + (stop - start));

        //iteracja iterator while
        start = System.nanoTime();
        while(list1.iterator().hasNext()){
        }
        stop = System.nanoTime();
        System.out.println("Czas iteracji iterator while ArrayList: " + (stop - start));

    }

    public static void zad1(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Podaj słowo do przetłumaczenia");
        String slowo = sc.nextLine();
        Path myPath = Paths.get("angpol.dic");
        Charset charset = Charset.forName("UTF-8");
        try {
            BufferedReader inFile = Files.newBufferedReader(myPath,charset);
            String line;
            while ((line = inFile.readLine()) != null) {
                String[] words = line.split(",");
                Translation translation = null;
                if(words.length == 5)
                    translation = new Translation(Integer.parseInt(words[1]),words[2],words[3],words[4]);
                else if(words.length == 4){
                    translation = new Translation(Integer.parseInt(words[1]),words[2],words[3],null);
                }
                else if(words.length == 3){
                    translation = new Translation(Integer.parseInt(words[1]),words[2],null,null);
                }
                else{
                    System.out.println("Nieprawidłowa liczba słów w linii");
                }
                dictionary.put(words[0],translation);
            }
        }catch (IOException e){
            System.out.println("Nie znaleziono pliku");
        }

        Path outPath = Paths.get("history.dat");
        Translation translation = dictionary.get(slowo);
        try {
            OutputStream outFile = Files.newOutputStream(outPath, CREATE, APPEND);
            if(translation != null){
                outFile.write((slowo + " ").getBytes(),0 ,slowo.length());
                outFile.write((translation.toString() + "\n").getBytes(), 0, translation.toString().length() + 1);
            }
            else{
                outFile.write((slowo + " ").getBytes());
                outFile.write("null\n".getBytes());
            }
            outFile.close();
        }catch (IOException e){
            System.out.println("Problem z otwarciem pliku!");
        }
        if(translation != null){
            System.out.println(translation);
        }
        else{
            System.out.println("Nie znaleziono słowa");
        }
    }
}