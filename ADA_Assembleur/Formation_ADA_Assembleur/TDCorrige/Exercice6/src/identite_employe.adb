with Ada.Text_IO; use Ada.Text_IO;
package body identite_employe is

   procedure AfficheNom (Info : in InfoEmploye'Class) is
   begin
      Put_Line ("Nom               : " & Info.Nom);
      Put_Line ("Prenom            : " & Info.Prenom);
      Put_Line
        ("Date de naissance : " & Info.DateAnniversaire.Jour'Image & "/" &
         Info.DateAnniversaire.Mois'Image & "/" &
         Info.DateAnniversaire.Annee'Image);
   end AfficheNom;

   procedure AfficheListe (Info : in T_Info) is
      type T_Nom is array (Positive range Info'Range) of SNOM;
   begin
      for i in Info'Range loop
         AfficheNom (Info (i));
         New_Line;
      end loop;
   end AfficheListe;

   procedure TriNom (Info : in out T_Info) is
      Tri1N   : SNOM;
      Tri2N   : SNOM;
      InfoTmp : T_Info (Info'Range);
      index   : Integer := Info'Length;
   begin
      for i in Info'Range loop
         Tri1N := Info (i).Nom;
         for j in Info'Range loop
            Tri2N := Info (j).Nom;
            if Tri1N < Tri2N then
               index := index - 1;
            end if;
         end loop;
         InfoTmp (index) := copy_T_Info (Info => Info (i));
         index           := Info'Length;
      end loop;

      for i in Info'Range loop
         Info (index) := copy_T_Info (Info => InfoTmp (i));
      end loop;
   end TriNom;

   function copy_T_Info (Info : InfoEmploye) return InfoEmploye is
   begin
      return
        (Nom              => Info.Nom, Prenom => Info.Prenom,
         DateAnniversaire =>
           (Info.DateAnniversaire.Jour, Info.DateAnniversaire.Mois,
            Info.DateAnniversaire.Annee));
   end copy_T_Info;
end identite_employe;
