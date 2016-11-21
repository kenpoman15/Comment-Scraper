/*
 *	Created by AJ Taft
 *	Created on 11-21-16
 *	Version 0.1
 *	Last Edited: 11-21-15
 */
package Scraper;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class scraper 
{
	
	public static void main(String args[])
	{
		//String to store the comments of the file
		String output = "";
				
		//Grabbing the file path from the console
		Scanner IFPscan = new Scanner(System.in);
		//Printing out to the user what to input
		System.out.println("Please input the file path of the file you want to scrap");
		String inputFile = IFPscan.next();
		
		
		try 
		{
			//Grabbing the file path from the console
			Scanner IFscan = new Scanner(new File(inputFile));
				
			//Run through the file until at the end line
			while(IFscan.hasNext())
			{
				String currentLine = IFscan.nextLine().trim();
				
				if(currentLine.length() > 2)
				{
					if(currentLine.substring(0,1).equals("*"))
					{
						output += currentLine.substring(2) + "\n";
					} else if(currentLine.substring(0,2).equals("//")) {
						output += currentLine.substring(2) + "\n";
					} else if(currentLine.substring(0,2).equals("/*")) {
						output += currentLine.substring(2) + "\n";
					}
				}
			}
			//Closing the file
			IFscan.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		IFPscan.close();
		//trying to write the output file
		try
		{
			File outputFile = new File("comments.txt");
			FileWriter writer = new FileWriter(outputFile);
			
			writer.write(output);
			writer.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}	
	}
}
