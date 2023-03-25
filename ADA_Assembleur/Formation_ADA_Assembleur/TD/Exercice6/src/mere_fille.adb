With ada.text_IO ;                Use Ada.Text_IO ; 

package body Mere.fille is
   procedure Attaque_de_flanc(Attaquant, Defenseur : in out T_Unit) is
   begin
      Put_line("   >> Attaque par le flanc ouest !") ; 
      Defenseur.vie := integer'max(0,Defenseur.vie - Attaquant.att*Attaquant.mov) ;
   end Attaque_de_flanc ; 
   
   procedure Tri_nom (Table : in out T_Info) is
      Tmp : InfoEmploye;
   begin
      for I in Table'Range loop
         for J in I + 1 .. Table'Last loop
            if Table(I).Nom  > Table(J).Nom  then
               Tmp := Table(I) ;
               Table(I)  := Table(J) ;
               Table(J)  := Tmp;
            end if;
         end loop;
      end loop;
   end Tri_nom;
   
end Mere.fille ;
