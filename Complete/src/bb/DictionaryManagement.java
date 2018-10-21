/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bb;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.io.FileReader;
import java.util.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;



/**
 *
 * @author thang
 */
public class DictionaryManagement {
       
 
    public String insertWord(){
        Scanner scanIn=new Scanner(System.in); 
        String target = ""; 
        target = scanIn.nextLine(); 
        return target;
    }
    public void insertFromCommandline()
    {
         System.out.println("nhap tu TA truoc TV sau ");
         DictionaryManagement dm = new DictionaryManagement();
         String target =dm.insertWord();
         if(null==Dictionary.store.get(target)){
         Dictionary.store.put(target,dm.insertWord());
         return;
         }
         System.out.println("Da co tu nay trong tu dien");
         
    }
    public void insert(String target,String explain)
    {
         Dictionary.store.put(target, explain);
    }
    
    public void insertFromFile(){
         InputStream inputStream = this.getClass().getResourceAsStream("/dic.txt");
         InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
         BufferedReader br = null;
         DictionaryManagement dm =new DictionaryManagement();
        try {   
            br = new BufferedReader(inputStreamReader);       
            int num=0;
            String textInALine;

            while ((textInALine = br.readLine()) != null) {
                
                for (int i=0;i<textInALine.length();i++){
                    if('|'==textInALine.charAt(i)){
                        dm.insert(textInALine.substring(0,i), textInALine.substring(i+1));
                    } 
                }
                
            }
        } catch (IOException e) {
            System.out.println("Error!!");
        }
    
    }
    
    public void exportToFile(){
        File file = new File("");                           //tao flie
        File fileData = new File (file.getAbsolutePath()+"\\src\\dic.txt");
        
        try {
            try (FileWriter fw = new FileWriter(fileData)) {
                String lineData;
                Set<String> keySet=Dictionary.store.keySet();
                for (String i:keySet){
                    lineData = i+"|"+Dictionary.store.get(i)+"\r\n";
                    fw.write(lineData);
                }
                System.out.println("Success");
            }
        } catch (IOException ex) {                                              //in ra "Error" neu phat hien loi
            System.out.println("Error!!");
        }
        
    }
    
    public String dictionaryLookup(String key){
        String temp=Dictionary.store.get(key);
        if (temp==null) return "LOI: Chua co tu nay";
        return temp;
    }
    public void remove(String key){
        Dictionary.store.remove(key);
    }
    public void replace(String key,String newVal){
        if(Dictionary.store.get(key)==null){
            System.out.println("ko co tu nay");
            return;
        }            
        Dictionary.store.replace(key,newVal);
    }
    
    public void showAllKey(){
        
        Set<String> keySet=Dictionary.store.keySet();
       
        for (String i:keySet) {
            
            
            
            System.out.println(i);
           
        }
    }
    
    
}
