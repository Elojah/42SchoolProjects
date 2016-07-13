#ifndef TEXT_JUSTIFY_HPP
# define TEXT_JUSTIFY_HPP

typedef char* PCXSTR;
typedef bool BOOL;
#define TRUE true
#define FALSE false
#define XMALLOC malloc

// Structure utilisée pour save chaque mot, sa position (x/y) et sa largeur.
struct STInfoMot
{
	PCXSTR	pszMot;
	int		nX;
	int		nY;
	int		nLargeur;
};

// Interface du visiteur !à réimplementer
class IVisiteurJustifier
{
public:
	virtual BOOL	bVisit(const STInfoMot *stInfoMot) = 0;
};

// Interface determinant la largeur des mots !à réimplementer
class ITailleMots
{
public:
	//nGetTailleMot sera appelée régulièrement pour justifier selon la font
	// Retournera toujours 1 par exemple dans le cas d'une font mono
	virtual int		nGetTailleMot(const PCXSTR pszMot) = 0;
};

class CTextJustify
{
public:
	CTextJustify(void);
	virtual ~CTextJustify(void);
	// Fonction principale:
	// pszTxt: Texte à justifier
	// piTm: Interface qui determine la taille des mots
	// nLargeurLigne, nHauteurLigne
	BOOL			bJustifie(PCXSTR pszTxt, ITailleMots *piTm
							, int nLargeurLigne, int nHauteurLigne);
	// Même fonction mais garde l'ancien txt et tm
	BOOL			bJustifie(int nLargeurLigne, int nHauteurLigne);
	// Fonction de visite
	void			accept(IVisiteurJustifier *piVisiteur) const;
	void			__display(void);
protected:
	// Tableau qui enregistre chaque mot et ses données
	STInfoMot		*m_tabInfoMot;
	// Taille du tableau
	int				m_nWords;
	// Tailles paramètres
	int				m_nHauteurLigne;
	int				m_nLargeurLigne;
	int				m_nSepSize;
	// Pointeur qui parcoure une fois la chaîne pour enregistrer les mots
	// Sera au '\0' à la fin
	PCXSTR			m_pszTxt;
	// Donne la taille des mots
	ITailleMots		*m_piTm;
	// Boolean indiquant si on réécrit les mots et leur largeur
	BOOL			m_bRewriteTxt;
private:
	void			_setNextWordStr(int nIndex);
	void			_setNextWordPosition(int nIndex, int nWidth, int nLine);
	BOOL			_bCompenseLigne(int nIndex, int nWidth, int nLine);
	void			_resetTab(void);
	static int		_nCountWords(PCXSTR pszTxt);
};

#endif
