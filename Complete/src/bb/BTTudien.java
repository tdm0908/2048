/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bb;

import java.io.IOException;
import java.util.*;
import java.util.Map.Entry;
import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author thang
 */
public class BTTudien {

    /**
     * @param args the command line arguments
     */
        
        public void loop()  {
        int temp;
        Scanner scanIn=new Scanner(System.in); 
        BTTudien bt=new BTTudien();
        DictionaryManagement dm = new DictionaryManagement();
        DictionaryCommandline dc = new DictionaryCommandline();
        
        
        System.out.println("nhan \n1 de them tu \n2 de xoa \n3 sua \n4 tim tu \n5 ghi lai vao file \n6 thoat ct va k ghi de \n7 hien tat ca tu dien\n8 thoat ct");
        
        
        temp=scanIn.nextInt();
        switch (temp){
            case 1:
                dm.insertFromCommandline();
                bt.loop();
                break;
            case 2:
                System.out.println("nhap vao tu can xoa");
                dm.remove(dm.insertWord());
                bt.loop();
                break;
            case 3:   
                System.out.println("nhap vao target va newValua");
                dm.replace(dm.insertWord(), dm.insertWord());
                bt.loop();
                break;
            case 4:
                System.out.println("nhap vao target");
                System.out.println(dm.dictionaryLookup(dm.insertWord()));
                break;
            case 5:
                dm.exportToFile();
                bt.loop();
                break;
                
            case 7:
                System.out.println("tu dien full");
                dc.showAllWords();
                bt.loop();
                break;
            case 8:
                dm.exportToFile();
                System.exit(0);
            case 9:
                dm.insertFromFile();
                bt.loop();
            default:
                System.out.println("nhap k dung lenh");
                bt.loop();
                
        }
        
    }  

    public static void main(String[] args) {
       
       BTTudien bt=new BTTudien();
       DictionaryManagement DicMan=new DictionaryManagement();
       DictionaryCommandline cml = new DictionaryCommandline();
       DicMan.insertFromFile();
       String i="thang";
       String j="4";
       Dictionary.store.replace(i, j);
       cml.showAllWords();
       DicMan.exportToFile();
      
      
       cml.showAllWords();
       
       
       }

   
   
    
}
