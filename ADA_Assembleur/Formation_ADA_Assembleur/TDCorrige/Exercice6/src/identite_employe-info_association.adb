with Ada.Text_IO; use Ada.Text_IO;
package body identite_employe.info_association is

   procedure donnation (info : info_benevole_association; don : Float) is

   begin
      Put_Line
        ("====================================================================");
      AfficheNom (Info => info);
      Put_Line ("Merci pour le don de " & don'Image & " euros");

      Put_Line
        ("====================================================================");
   end donnation;

end identite_employe.info_association;
