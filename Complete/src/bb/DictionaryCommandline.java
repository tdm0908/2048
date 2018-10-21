/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bb;

import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.Scanner;

/**
 *
 * @author thang
 */
public class DictionaryCommandline {
    
    
    public void showAllWords(){
        
        Set<String> keySet=Dictionary.store.keySet();
        for (String i:keySet) System.out.println(i+"|"+Dictionary.store.get(i));
    }
    public void dictionaryBasic() {
        DictionaryCommandline dc=new DictionaryCommandline();
        DictionaryManagement  dm=new DictionaryManagement();
        dc.showAllWords();
        dm.insertFromCommandline();
    }
    public void dictionarySearcher (){                                          //ham tim ca tu bat dau bang "..."
        System.out.print("type a part of word: ");
        Scanner sc = new Scanner(System.in);
        String inputAPartOfWord = sc.nextLine();                                //nhap cum tu bat dau
        int length_inputAPartOfWord = inputAPartOfWord.length();                //lay do dai cua cum tu do
        System.out.println("RESULT");
        
        Set<String> keySet=Dictionary.store.keySet();
       
        for (String i:keySet) {
            if(i.substring(0, length_inputAPartOfWord).toUpperCase().equals(inputAPartOfWord.toUpperCase())){
                System.out.println(i);
            }
            
            
            
           
        }
        }
    }
   

