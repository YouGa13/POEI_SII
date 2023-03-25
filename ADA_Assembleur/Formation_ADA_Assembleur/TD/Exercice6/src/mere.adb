with Ada.Text_IO; use Ada.Text_IO;
package body Mere is

   procedure Afficher_nom (Info : in out T_Info) is
   begin
      for i in Info'Range loop
         Put_Line ("Nom de l'employé : " & Info (i).Nom);
         New_Line;
      end loop;
   end Afficher_nom;
   
end Mere ;
