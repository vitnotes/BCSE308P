import java.util.*;
public class IspProblem 
{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        System.out.print("Enter the starting address for the block: ");
        String s=in.nextLine();
        int g,i,c,a,sum=0;
        System.out.print("Enter the number of groups: ");
        g=in.nextInt();
        String str1="";
        String fin="";
        String z="";
        str1=s.substring(0,s.indexOf('.',6)+1);
        int sec=Integer.parseInt(s.substring(s.lastIndexOf('.')+1, s.indexOf('/')));
        int fir=Integer.parseInt(s.substring(s.indexOf('.',6)+1, s.lastIndexOf('.')));
        for (i=0;i<g;i++)
        {
            System.out.println("\nEnter Details of Group"+(i+1)+" : ");
            System.out.print("Enter the number of customers in Group"+(i+1)+" : ");
            c=in.nextInt();
            System.out.print("Enter the number of addresses in Group"+(i+1)+" : ");
            a=in.nextInt();
            int suffix=(int)(Math.ceil(Math.log(a)/Math.log(2)));
            System.out.println("Suffix Length = "+suffix+" (2^"+suffix+"="+a+")");
            int pre=32-suffix;
            System.out.println("Prefix Length is 32-"+suffix+" = "+pre);
            String str="";
            System.out.print("Address of Customer 1 : ");
            if (fir==0 && sec==0)
            {
                z=s.substring(0,s.indexOf('/')+1)+pre;
                fin=z;
                System.out.print(z+" to ");
                if (sec<255)
                {
                    sec+=a-1;
                }
                else
                {
                    fir+=1;
                    sec=0;
                }
                str=str1+fir+'.'+sec+'/'+pre;
                System.out.println(str);
            }
            else
            {
                if (sec<255)
                {
                    sec+=a-1;
                }
                else
                {
                    fir+=1;
                    sec=0;
                }
                str=str1+fir+'.'+sec+'/'+pre;
                fin=str;
                System.out.print(str+" to ");
                if (sec<255)
                {
                    sec+=a-1;
                }
                else
                {
                    fir+=1;
                    sec=0;
                }
                str=str1+fir+'.'+sec+'/'+pre;
                System.out.println(str);
            }
            System.out.print("Address of Customer 2 : ");
            if (sec<255)
            {
                sec+=1;
            }
            else
            {
                fir+=1;
                sec=0;
            }
            str=str1+fir+'.'+sec+'/'+pre;
            System.out.print(str+" to ");
            if (sec<255)
            {
                sec+=a-1;
            }
            else
            {
                fir+=1;
                sec=0;
            }
            str=str1+fir+'.'+sec+'/'+pre;
            System.out.println(str);
            System.out.println("...................");
            System.out.print("Address of Customer "+c+" : ");
            int j=256/a;
            int k=c/j;
            fir=Integer.parseInt(fin.substring(fin.indexOf('.',6)+1, fin.lastIndexOf('.')));
            fir=fir+k-1;
            sec=255-a+1;
            str=str1+fir+'.'+sec+'/'+pre;
            System.out.print(str+" to ");
            sec=255;
            str=str1+fir+'.'+sec+'/'+pre;
            System.out.println(str);
            System.out.println("Total number of addresses used in Group"+(i+1)+" = "+(c*a));
            sum+=c*a;
        }
        String p=s.substring(s.indexOf('/')+1);
        int t=Integer.parseInt(p);
        int x=32-t;
        int y=(int)Math.pow(2,x);
        System.out.println("\nNumber of granted addresses = "+y);
        System.out.println("Number of allocated addresses = "+sum);
        System.out.println("Number of available addresses = "+(y-sum));
    }
}