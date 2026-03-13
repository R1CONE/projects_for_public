SELECT * FROM CDN.TraNag Order By TrN_DataDok DESC
SElECT * FROM CDN.TraNag WHERE TrN_Termin = '2026-03-18';
UPDATE CDN.TraNag SET Trn_Bufor = 0 WHERE TrN_TrNID = 533;




SELECT TOP (1000) Knt_KntId

select * from cdn.PracEtaty
select * from cdn.Pracidx


SELECT TOP (1000) [TrN_TrNID]
      ,[TrN_TerminZwrotuKaucji]
      ,[TrN_OFFPrawoDoFAPA]
      ,[TrN_OFFPrawoDoAnulowania]
      ,[TrN_RelTrNId]
      ,[TrN_FVMarza]



select TrNNumerPelny,trn * FROM [CDN_Firma_Demo_1_1].[CDN].[TraNag] WHERE TrN_NumerPelny LIKE 'FZ%'

select * from cdn.Pracidx

CREATE PROCEDURE idk
    @PriId int
AS
BEGIN
    DECLARE @TrN_TrNId int;
    SELECT @TrN_TrNId = TrN_TrNID FROM CDN.TraNag WHERE TrN_OdbiorcaTyp = 3 AND TrN_OdbID = @PriId AND TrN_NumerString LIKE 'FZ%'
END;
R1CONE [cvrs],  — Вчера, в 12:27
CREATE PROCEDURE idk
    @PriId int
AS
BEGIN
    DECLARE @TrN_TrNId int;

    SELECT TOP 1 
        @TrN_TrNId = TrN_TrNID
    FROM CDN.TraNag
    WHERE TrN_OdbiorcaTyp = 3 
      AND TrN_OdbID = @PriId
      AND TrN_NumerString LIKE 'FZ%'
    ORDER BY TrN_DataWys DESC;

END;



CREATE PROCEDURE idk
    @PriId int
AS
BEGIN

    DECLARE @TrNId int;

    SELECT TOP 1 @TrNId = TrN_TrNID FROM CDN.TraNag
    WHERE TrN_OdbiorcaTyp = 3
    AND TrN_OdbID = @PriId
    AND TrN_NumerString LIKE 'FZ%'
    ORDER BY TrN_TrNId DESC

    DECLARE @KrNId int;

    SELECT @KrNId = TrN_PlatnikID FROM CDN.TraNag
    WHERE TrN_TrNID = @TrNId;

    print @TrNId;
    print @KrNId;


END;
R1CONE [cvrs],  — Вчера, в 14:01
select * from cdn.DefProjekty
  select * from cdn.Dzialy
  select * from cdn.tranag
  select * from cdn.Wymiary
  select * from cdn.WymiaryWartosci
R1CONE [cvrs],  — Вчера, в 14:14
select * from cdn.Dzialy - названия всех видов дейтельностей куда может пойти процент
select * from cdn.WymiaryWartosci -- таблица с вартощсиами этих хуен
R1CONE [cvrs],  — 10:16
DZL_Dzlld.Dzialy =
select * from cdn.Dzialy
select * from cdn.WymiaryWartosci
R1CONE [cvrs],  — 11:13
Maciej 19 - by 1 to 19
