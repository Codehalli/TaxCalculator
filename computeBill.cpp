/*
*  Purpose for program
*  This project will calculate the total bill after computing the taxes on an amount. 
*  The Tax rate changes depending on the slab in which the total amount falls.
*
*  Programmer: Pranav Rao
*  Date: Feburary 19, 2019
*
*/

#include "computeBill.h"

void computeBill( istream& in, ostream& out )
{
  
	double sub_total, min_spending, max_spending, total;  //declaring the variables that I will read in
	double rate_1, rate_2, rate_3;                        //declaring the variable rates
	double extra, taxes, full_total;                      //declaring the output variables 
	double tax1, tax2, tax3;                              //declaring the taxes
	
	//use in to read the input
	in >> sub_total >> min_spending >> max_spending >> rate_1 >> rate_2 >> rate_3;
	

	if(sub_total == min_spending)                       //this selection statement work when subtotal equals min thresholds
	{ 
	   
	  extra = 0;                                       //calculations for the taxes
	  
	  tax1 = rate_1 * sub_total / 100;                 
	  tax2 = 0;
	  tax3 = 0;
	  
	  taxes = tax1 + tax2 + tax3;
	  full_total = sub_total + taxes;

	  //use out to write output for Web-CAT to grade	
	  out << "Subtotal: $" << fixed << setprecision(2) << sub_total << endl;                                  //displaying the output values         
	  out << "Tax: $" << setprecision(2) << taxes << endl;                      
	  out << "Total: $" << setprecision(2) << full_total << endl;              
	  out << "Breakdown:" << endl;
	  out << "$" << setprecision(2) << sub_total << " taxed at " << setprecision(0) << rate_1 << "% for $" << 
	  setprecision(2) << tax1 << endl; 
	  
	}
	else if( sub_total < min_spending )               //this selection works only if the subtotal is less than min thresholds
	{
		
	  tax1 = rate_1 * sub_total / 100;                           
	  tax2 = 0;
	  tax3 = 0;
	  
	  taxes = tax1 + tax2 + tax3;
	  full_total = sub_total + taxes;
	  
	  //use out to write output for Web-CAT to grade
	  out << "Subtotal: $" << fixed << setprecision(2) << sub_total << endl;                  
	  out << "Tax: $" << setprecision(2) << taxes << endl;                            
	  out << "Total: $" << setprecision(2) << full_total << endl;                    
	  out << "Breakdown:" << endl;
	  out << "$" << setprecision(2) << sub_total << " taxed at " << setprecision(0) << rate_1 << "% for $" << 
	  setprecision(2) << tax1 << endl; 
	}
	
	else if (max_spending < sub_total && sub_total > min_spending)        //this selection works subtotal  is greater than both thresholds
	{	
		
		extra= max_spending - min_spending;                             //calculations taxes
		tax3 = rate_3 * (sub_total - max_spending) / 100;        
		tax2 = rate_2 * extra  / 100;
		tax1 = rate_1 * min_spending / 100;
		
		taxes = tax1 + tax2 + tax3;
		full_total = sub_total + taxes;
		
		//use out to write output for Web-CAT to grade
		out<< "Subtotal: $" << fixed << setprecision(2) << sub_total <<endl;              //displaying the output values
		out<< "Tax: $" << setprecision(2) << taxes <<endl;                        
		out<< "Total: $" << setprecision(2) << full_total <<endl;                 
		out<< "Breakdown:" <<endl;
		out<< "$" << setprecision(2) << min_spending << " taxed at " << setprecision(0) << rate_1 <<"% for $" 
		<< setprecision(2) << tax1 <<endl; 
		out<< "$" << setprecision(2) << extra << " taxed at " << setprecision(0) << rate_2 <<"% for $" 
		<< setprecision(2) << tax2 << endl; 
		out<< "$" << setprecision(2) << (sub_total-max_spending) << " taxed at " << setprecision(0) << rate_3 <<"% for $" 
		<< setprecision(2) << tax3 << endl;
		
	}
	
	else if (min_spending < sub_total && max_spending >= sub_total)           // this selection will work when subtotal is greater than 
	{                                                                         // min spending and less than max spending
		
	  extra = sub_total - min_spending;                                    //calcutation for taxes
	  tax3 = 0;                                                    
	  tax2 = rate_2 * extra / 100;
	  tax1 = rate_1 * min_spending / 100;
	  
	  taxes = tax1 + tax2 + tax3;
	  full_total = sub_total + taxes;
	  
	  //use out to write output for Web-CAT to grade
	  out << "Subtotal: $" << fixed << setprecision(2) << sub_total << endl;                   //displaying the output values 
	  out << "Tax: $" << setprecision(2) << taxes << endl;                            
	  out << "Total: $" << setprecision(2) << full_total << endl;                     
	  out << "Breakdown:" << endl;
	  out << "$" << setprecision(2) << min_spending << " taxed at " << setprecision(0) << rate_1 << "% for $" << 
	  setprecision(2) << tax1<< endl; 
	  out << "$" << setprecision(2) << extra << " taxed at " << setprecision(0) << rate_2 << "% for $" << 
	  setprecision(2) << tax2 << endl;
	  
	}
	
	else
	{ 
	}
	 
}