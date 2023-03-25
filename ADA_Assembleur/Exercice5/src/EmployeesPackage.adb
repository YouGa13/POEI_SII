package body EmployeesPackage is
--------------------------------------------------------------------------------   
    procedure Display_Date (ADate : Date) is
    begin
        Put_Line ("Year :" & Natural'Image (ADate.year));
        Put_Line ("Month:" & Natural'Image (ADate.month));
        Put_Line ("Day  :" & Natural'Image (ADate.day));
    end Display_Date;
--------------------------------------------------------------------------------
    procedure Print_Employee (Personn : in Employee) is
    begin
        Put_Line ("Name    : " & Personn.name);
        Put_Line ("Function: " & Personn.func'Image);
        Put_Line ("Salary  :"  & Personn.salary'Image);
    end Print_Employee;
--------------------------------------------------------------------------------
    procedure Print_All_Employees (Company : in EmployeesList) is
    begin
        for i in Company'Range loop
            Print_Employee(Company (i));
            Put_Line ("");
        end loop;
   end Print_All_Employees;
--------------------------------------------------------------------------------
    procedure Set_Salary (Personn : in out Employee; Salary : in Float) is
    begin
       Personn.salary := Salary;        
    end Set_Salary;
--------------------------------------------------------------------------------
    function Get_Max_Non_Boss_Salary(Company : in EmployeesList) return Float is
    max : Float;
    begin
        max := 0.0;
        for i in Company'Range loop
            if Company(i).func /= BOSS then
                if Company (i).salary > max then
                    max := Company (i).salary;
                end if;
            end if;
        end loop;
      
      if max = 0.0 then
         Put_Line("No salaried, only boss!");
      end if;
        return max;
   end Get_Max_Non_Boss_Salary;
--------------------------------------------------------------------------------
    function Get_Min_Boss_Salary(Company : in EmployeesList) return Float is
    min : Float;
    begin
        min := float'Last;
        for i in Company'Range loop
            if Company(i).func = BOSS then
                if Company (i).salary < min then
                    min := Company (i).salary;
                end if;
            end if;
        end loop;
        if min = float'Last then
            Put_Line("No boss!");
        end if;
        return min;
    end Get_Min_Boss_Salary;
--------------------------------------------------------------------------------    
    procedure Give_Raise (Company : in out EmployeesList; who : in String; percentage : in float) is
    TOO_BIG, TOO_LOW : exception;
    boss_min : Float;
    new_salary : Float;
    non_boss_max : Float;
    begin
        boss_min := Get_Min_Boss_Salary(Company);
        non_boss_max := Get_Max_Non_Boss_Salary(Company);
        for i in Company'Range loop
            if Company (i).name = who then
                new_salary := Company(i).salary * (1.0+percentage);
            
                if Company(i).func /= BOSS then
                   if ( (boss_min /= 0.0) and (new_salary > boss_min) ) then
                       raise TOO_BIG with "Cannot have salary bigger than a boss!";
                   end if;
                else
                   if ( (boss_min /= float'Last) and (new_salary < non_boss_max) ) then
                      raise TOO_LOW with "Cannot have salary lower than a salaried!";
                   end if;
                end if;
                Set_Salary(Company(i), new_salary);
            end if;
        end loop;
    end Give_Raise;
--------------------------------------------------------------------------------
 function "<" (L, R : Employee) return Boolean is
 begin
      return L.name < R.name;
 end "<";  
-------------------------------------------------------------------------------- 
procedure Quick_Sort (Company : in out EmployeesList) is

   procedure Swap(Left, Right : Integer) is
      Temp : Employee := Company(Left);
   begin
      Company(Left) := Company(Right);
      Company(Right) := Temp;
   end Swap;
  
begin
   if Company'Length > 1 then
   declare
      Pivot_Value : Employee := Company(Company'First);
      Right       : Integer := Company'Last;
      Left        : Integer := Company'First;
   begin
       loop
          while Left < Right and not (Pivot_Value < Company(Left)) loop
             Left := Integer'Succ (Left);
          end loop;
          while Pivot_Value < Company(Right) loop
             Right := Integer'Pred (Right);
          end loop;
          exit when Right <= Left;
          Swap (Left, Right);
          Left := Integer'Succ (Left);
          Right := Integer'Pred (Right);
       end loop;
       if Right = Company'Last then
          Right := Integer'Pred (Right);
          Swap (Company'First, Company'Last);
       end if;
       if Left = Company'First then
          Left := Integer'Succ (Left);
       end if;
       Quick_Sort (Company(Company'First .. Right));
       Quick_Sort (Company(Left .. Company'Last));
   end;
   end if;
end Quick_Sort;   
    
end EmployeesPackage;
