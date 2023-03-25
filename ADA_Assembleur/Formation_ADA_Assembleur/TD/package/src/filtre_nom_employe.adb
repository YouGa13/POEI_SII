with Ada.Text_IO;             use Ada.Text_IO;
package body filtre_nom_employe is 
  procedure Tri_salaire (Table : in out T_Info) is
      Tmp : InfoEmploye;
   begin
      for I in Table'Range loop
         for J in I + 1 .. Table'Last loop
            if Table(I).Salaire  > Table(J).Salaire  then
               Tmp := Table(I) ;
               Table(I)  := Table(J) ;
               Table(J)  := Tmp;
            end if;
         end loop;
      end loop;
   end Tri_salaire;
   
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
   
   procedure update_salaire (u_salaire : in out Float; Table : in out InfoEmploye ) is
      Tmp_salaire : Float := u_salaire;
      Tmp_table : InfoEmploye := Table;
     begin
          Tmp_table.Salaire := Tmp_salaire;
   end update_salaire;
   
   procedure afficher_salaire (Table : in out T_Info) is 
      begin
        for i in Table'Range loop
         Put_Line ("Salaire de l'employé" & Integer'Image(i) & " : " & Table(i).Salaire'Image);
         New_Line;
        end loop;
   end afficher_salaire;
   
   procedure afficher_employe_tri_nom (Table : in out T_Info) is 
      begin 
        for i in Table'Range loop
         Put_Line ("Nom de l'employé : " & Table(i).Nom);
         New_Line;
      end loop;
   end afficher_employe_tri_nom;
  end filtre_nom_employe;
