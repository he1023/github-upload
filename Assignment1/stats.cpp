//FILE:stats.cxx
//CLASS IMPLEMENTED:statistician(see stats.h for documentation)

#include <cassert>
#include "stats.h"

namespace main_savitch_2C
{
    statistician::statistician()
    {
        count=0;
        total=0;
        tinyest=0;
        largest=0;
        
    }
    
    void statistician::next(double r)
    {
        if(count==0)
        {
            total=r;
            count++;
            tinyest=r;
            largest=r;
        }
        else
        {
            total+=r;
            count+=1;
            if(r<tinyest)
                tinyest=r;
            if(r>largest)
                largest=r;
        }
    }
    void statistician::reset( )
    {
        count=0;
        total=0;
        tinyest=0;
        largest=0;
    }
    int statistician::length() const
    {
        
        return count;
    }
    double statistician::sum() const
    {
        return total;
    }
    double statistician::mean() const
    {
        if(length()>0)
            return sum()/count;
        return 0.0;
    }
    double statistician::minimum() const
    {
        if(length()>0)
            return tinyest;
        return 0.0;
    }
    double statistician::maximum() const
    {
        if(length()>0)
            return largest;
        return 0.0;
    }
    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician x;
        x.total=s1.sum()+s2.sum();
        x.count=s1.length()+s2.length();
        if(s1.maximum()>s2.maximum())
            x.largest=s1.maximum();
        else
            x.largest=s2.maximum();
        if(s1.minimum()>s2.minimum())
            x.tinyest=s2.minimum();
        else
            x.tinyest=s1.minimum();
        return x;
    }
    statistician operator * (double scale, const statistician& s)
    {
        if(s.length()==0)
            return s;
        
        
        else if(scale>=0)
        {
            statistician x;
            x.largest=s.maximum()*scale;
            x.tinyest=s.minimum()*scale;
            x.total=s.sum()*scale;
            x.count=s.length();
            return x;
        }
        else if(scale<0)
        {
            statistician y;
            y.tinyest=s.maximum()*scale;
            if(s.minimum()==0)
                y.largest=0;
            else
                y.largest=s.minimum()*scale;
            y.total=s.total*scale;
            y.count=s.length();
            
            return y;
        }
        return s;
    }
    
    
    
    
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.maximum()==s2.maximum())
        {
            if(s1.minimum()==s2.minimum())
            {
                if(s1.length()==s2.length())
                {
                    if(s1.sum()==s1.sum())
                        return true;
                }
            }
            
            
            
            
        }
        return false;
    }
}

